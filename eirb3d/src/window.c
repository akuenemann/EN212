﻿#include "window.h"
#include "geometry.h"
#include "model.h"
#include "vector.h"

static void WindowUpdateTexture( window_t * w ) {
	Uint32 * dst;
	int row, col;
	void * pixels;
	int pitch;
	if ( SDL_LockTexture( w->texture, NULL, &pixels, &pitch ) < 0 ) {
		SDL_LogError( SDL_LOG_CATEGORY_APPLICATION, "Couldn't lock texture: %s\n", SDL_GetError() );
		SDL_Quit();
	}
	Uint8 * ptr = w->framebuffer;
	for ( row = 0; row < w->height; ++row ) {
		dst = (Uint32*)( (Uint8*)pixels + row * pitch );
		for ( col = 0; col < w->width; ++col ) {
			Uint8 b = *ptr++;
			Uint8 g = *ptr++;
			Uint8 r = *ptr++;
			Uint8 a = *ptr++;
			*dst++ = ( ( b << 24 ) | ( g << 16 ) | ( r << 8 ) | a );
		}
	}
	SDL_UnlockTexture( w->texture );
}

static Uint8 * WindowInitFramebuffer( window_t * w ) {
	size_t sz = w->width * w->height * w->bpp * sizeof( Uint8 );
	Uint8 * buffer = (Uint8*)malloc( sz );
	if ( buffer == NULL) return NULL;
	memset( buffer, 0, sz );
	return buffer;
}

window_t * WindowInit( int width, int height, int bpp ) {

	if ( SDL_Init( SDL_INIT_VIDEO ) != 0 ) {
		printf( "SDL_Init Error: %s", SDL_GetError() );
		return NULL;
	}

	SDL_Window * sdlwindow = SDL_CreateWindow(	"Software OpenGL renderer", 
												SDL_WINDOWPOS_CENTERED, 
												SDL_WINDOWPOS_CENTERED, 
												width, height,
												SDL_WINDOW_ALLOW_HIGHDPI );

	if ( sdlwindow == NULL ) {
		SDL_LogError( SDL_LOG_CATEGORY_APPLICATION, "Couldn't create SDL window: %s", SDL_GetError() );
		SDL_DestroyWindow( sdlwindow );
		SDL_Quit();
		return NULL;
	}

	SDL_Renderer * renderer = SDL_CreateRenderer( sdlwindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );

	if ( renderer == NULL ) {
		SDL_LogError( SDL_LOG_CATEGORY_APPLICATION, "Couldn't create renderer: %s", SDL_GetError() );
		SDL_DestroyRenderer( renderer );
		SDL_Quit();
		return NULL;
	}

	SDL_Texture * texture = SDL_CreateTexture( renderer, SDL_PIXELFORMAT_BGRA8888, SDL_TEXTUREACCESS_STREAMING, width, height );
	
	if ( texture == NULL ) {
		SDL_LogError( SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture: %s\n", SDL_GetError() );
		SDL_DestroyTexture( texture );
		SDL_Quit();
		return NULL;
	}

	window_t * mainwindow = (window_t*)malloc( sizeof( window_t ) );

	if ( mainwindow == NULL ) {
		SDL_LogError( SDL_LOG_CATEGORY_APPLICATION, "Couldn't allocate window\n" );
		SDL_Quit();
		return NULL;
	}

	mainwindow->width	= width;
	mainwindow->height	= height;
	mainwindow->bpp		= bpp;
	mainwindow->pitch	= width * bpp;

	Uint8 * framebuffer = WindowInitFramebuffer( mainwindow );

	if ( framebuffer == NULL ) {
		SDL_LogError( SDL_LOG_CATEGORY_APPLICATION, "Couldn't allocate framebuffer: %s\n", SDL_GetError() );
		SDL_Quit();
		return NULL;
	}

	mainwindow->framebuffer = framebuffer;
	mainwindow->sdlwindow	= sdlwindow;
	mainwindow->renderer	= renderer;
	mainwindow->texture		= texture;

	return mainwindow;
}

void WindowDestroy( window_t * w ) {
	SDL_DestroyRenderer( w->renderer );
	SDL_DestroyTexture( w->texture );
	SDL_DestroyWindow( w->sdlwindow );
	free( w->framebuffer );
	SDL_Quit();
}

void WindowUpdate( window_t * w ) {
	SDL_RenderClear( w->renderer );
	SDL_RenderCopy( w->renderer, w->texture, NULL, NULL );
	SDL_RenderPresent( w->renderer );
	WindowUpdateTexture( w );
}

void WindowDrawPoint( window_t * w, int x, int y, Uint8 r, Uint8 g, Uint8 b ) {
	Uint32 * dst = (Uint32*)w->framebuffer + y * w->width + x;
	*dst = (0xFF << 24) | (r << 16) | ( g << 8) | b;
}

void WindowDrawClearColor( window_t * w, Uint8 r, Uint8 g, Uint8 b ) {
	for ( int row = 0; row < w->height; row++ ) {
		for ( int col = 0; col < w->width; col++ ) {
			WindowDrawPoint(w, col, row, r, g, b);
		}
	}
}

void WindowDrawLine( window_t * w, int x0, int y0, int x1, int y1, Uint8 r, Uint8 g, Uint8 b ) {
	bool s = false;
	if ( (x1 - x0) == 0.0f ){
		int miny = MIN(y0, y1);
		int maxy = MAX(y0, y1);
		for (int y_courant = miny ; y_courant < maxy ; y_courant++){
			WindowDrawPoint(w, x0, y_courant, r, g, b);
		}
	}
	else{
		if ( (y1 - y0)/(x1 - x0) < 1){
			swap(&x0, &y0);
			swap(&x1, &y1);
			s = true;
		}

		float coef = (y1 - y0)/(x1 - x0);
		float offset = y0 - coef * x0;
		int minx   = MIN(x0, x1);
		int maxx   = MAX(x0, x1);

		int y_courant = 0;
		for (int x_courant = minx ; x_courant < maxx ; x_courant++){
			y_courant = coef*x_courant + offset;
			if(s){
				WindowDrawPoint(w, y_courant, x_courant, r, g, b);
			}
			else{
				WindowDrawPoint(w, x_courant, y_courant, r, g, b);
			}
		}
	}
	
}

void WindowDrawTriangle( window_t * w, int idx ) { 
		face_t * face = (face_t*) VectorGetFromIdx( ModelFaces(), idx );
		vec3f_t *s1 = (vec3f_t*) VectorGetFromIdx(ModelVertices(), face->v[0]-1);
		vec3f_t *s2 = (vec3f_t*) VectorGetFromIdx(ModelVertices(), face->v[1]-1);
		vec3f_t *s3 = (vec3f_t*) VectorGetFromIdx(ModelVertices(), face->v[2]-1);
		
		WindowDrawLine(w, (int) (s1->x+1)*w->width, (int) (s1->y+1)*w->height, (int) (s2->x+1)*w->width, (int) (s2->y+1)*w->height, 200, 200, 200);
		//WindowDrawLine(w, (int) s3->x, (int) s3->y, (int) s2->x, (int) s2->y, 200, 200, 200);
		//WindowDrawLine(w, (int) s1->x, (int) s1->y, (int) s3->x, (int) s3->y, 200, 200, 200);

}


