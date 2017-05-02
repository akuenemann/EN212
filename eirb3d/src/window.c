#include "window.h"
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
	*dst = (0x1F << 24) | (r << 16) | ( g << 8) | b;
}

void WindowDrawClearColor( window_t * w, Uint8 r, Uint8 g, Uint8 b ) {
	for ( int row = 0; row < w->height; row++ ) {
		for ( int col = 0; col < w->width; col++ ) {
			WindowDrawPoint(w, col, row, r, g, b);
		}
	}
}

void WindowDrawLine( window_t * w, int x0, int y0, int x1, int y1, Uint8 r, Uint8 g, Uint8 b ) {


  int dx,dy,i,x0nc,y0nc,cumul,x,y ;
  x = x0 ;
  y = y0 ;
  dx = x1 - x0 ;
  dy = y1 - y0 ;
  x0nc = ( dx > 0 ) ? 1 : -1 ;
  y0nc = ( dy > 0 ) ? 1 : -1 ;
  dx = abs(dx) ;
  dy = abs(dy) ;
  WindowDrawPoint(w, x, y, r, g, b);
  if ( dx > dy ) {
    cumul = dx / 2 ;
    for ( i = 1 ; i <= dx ; i++ ) {
      x += x0nc ;
      cumul += dy ;
      if ( cumul >= dx ) {
        cumul -= dx ;
        y += y0nc ; }
      WindowDrawPoint(w, x, y, r, g, b); } }
    else {
    cumul = dy / 2 ;
    for ( i = 1 ; i <= dy ; i++ ) {
      y += y0nc ;
      cumul += dx ;
      if ( cumul >= dy ) {
        cumul -= dy ;
        x += x0nc ; }
      WindowDrawPoint(w, x, y, r, g, b); } }





/*

	bool s = false;
	if ( (x1 - x0) == 0.0f ){
		int miny = MIN(y0, y1);
		int maxy = MAX(y0, y1);
		for (int y_courant = miny ; y_courant < maxy ; y_courant++){
			WindowDrawPoint(w, x0, y_courant, r, g, b);
		}
	}
	else if ( (y1 - y0) == 0.0f ){
		int minx = MIN(x0, x1);
		int maxx = MAX(x0, x1);
		for (int x_courant = minx ; x_courant < maxx ; x_courant++){
			WindowDrawPoint(w, x_courant, y0, r, g, b);
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
	}*/
	
}

void WindowDrawTriangle( window_t * w, int idx ) { 
	face_t * face = (face_t*) VectorGetFromIdx( ModelFaces(), idx );
	vec3f_t *s1 = (vec3f_t*) VectorGetFromIdx(ModelVertices(), face->v[0]-1);
	vec3f_t *s2 = (vec3f_t*) VectorGetFromIdx(ModelVertices(), face->v[1]-1);
	vec3f_t *s3 = (vec3f_t*) VectorGetFromIdx(ModelVertices(), face->v[2]-1);
	
	int x1 = (int) ((s1->x+1)*w->width/2);
	int y1 = (int) (w->height - (s1->y+1)*w->height/2);
	int z1 = (int) ((s1->z+1));
	int x2 = (int) ((s2->x+1)*w->width/2);
	int y2 = (int) (w->height - (s2->y+1)*w->height/2);
	int z2 = (int) ((s2->z+1));
	int x3 = (int) ((s3->x+1)*w->width/2);
	int y3 = (int) (w->height - (s3->y+1)*w->height/2);
	int z3 = (int) ((s3->z+1));

/*
	int x1 = 500;
	int y1 = 200;
	int x2 = 150;
	int y2 = 300;
	int x3 = 150;
	int y3 = 100;
*/
	//WindowDrawLine(w, x1, y1, x2, y2, 200, 200, 200);
	//WindowDrawLine(w, x3, y3, x2, y2, 200, 200, 200);
	//WindowDrawLine(w, x1, y1, x3, y3, 200, 200, 200);


	int tmpy;
	int tmpx;
	if(y1 > y3){
		if(y1 > y2){
			if(y2 > y3){
				tmpx = x3;
				tmpy = y3;
				y3 = y1;
				x3 = x1;
				y1 = tmpy;
				x1 = tmpx;
			}
			else{	
				tmpx = x3;
				tmpy = y3;
				y3 = y1;
				x3 = x1;
				y1 = y2;
				x1 = x2;
				y2 = tmpy;
				x2 = tmpx;
			}
		}
		else{
			tmpx = x3;
			tmpy = y3;
			y3 = y2;
			x3 = x2;
			y2 = y1;
			x2 = x1;
			y1 = tmpy;
			x1 = tmpx;
		}
	}
	else{
		if(y3 < y2){
			tmpx = x3;
			tmpy = y3;
			y3 = y2;
			x3 = x2;
			y2 = tmpy;
			x2 = tmpx;
		}
		else if(y1 > y2){
			tmpx = x2;
			tmpy = y2;
			y2 = y1;
			x2 = x1;
			y1 = tmpy;
			x1 = tmpx;
		}
	}

	//printf("x1 = %d, x2 = %d, x3 = %d\ny1 = %d, y2 = %d, y3 = %d\n", x1, x2 ,x3, y1, y2, y3);

float coef1 = 0;
float offset1 = 0;

float coef2 = 0;
float offset2 = 0;

float coef3 = 0;
float offset3 = 0;

bool c1 = false;
bool c2 = false;
bool c3 = false;

int lumiere[] = {0,0,1};

vec3f_t cote1 = Vec3fSub(*s1,*s2);
vec3f_t cote2 = Vec3fSub(*s2,*s3);

vec3f_t prod_vect = Vec3fNormalize(Vec3fCross( cote1, cote2 ));

float intensite = prod_vect.x*lumiere[0]+prod_vect.y*lumiere[1]+prod_vect.z*lumiere[2];


int couleur_r;

if (intensite < 0){
	//couleur_r = -intensite*255;
	return;
}
else{
	couleur_r = intensite*255;
}
int couleur_b = couleur_r;
int couleur_g = couleur_r;


if (!((x1 == x3) || (y1 == y3))){
	coef1 = (y3 - y1)/(float)(x3 - x1);
	offset1 = y1 - coef1 * x1;
	c1 = true;
	
}
if(!((x2 == x1) || (y2 == y1))){
	coef2 = (y2 - y1)/(float)(x2 - x1);
	offset2 = y1 - coef2 * x1;
	c2 = true;
}
if(!((x2 == x3) || (y2 == y3))){
	c3 = true;
	coef3 = (y3 - y2)/(float)(x3 - x2);
	offset3 = y2 - coef3 * x2;
}

//printf("%f %f %f\n", coef1, coef2, coef3);
//printf("%d %d %d\n", c1, c2, c3);





for (int y = y1; y <= y2; y++){
	if ((c1 == false) && (c2 == false)){
		WindowDrawPoint(w, x1, y, 255, 0, 0);
	} 
	else if(c1 == false){
		if (x1 < x2){
			WindowDrawLine(w, x1, y, (int)((y - offset2)/coef2), y, couleur_r, couleur_g, couleur_b);
		}
		else{
			WindowDrawLine(w, (int)((y - offset2)/coef2), y, x1, y, couleur_r, couleur_g, couleur_b);
		}
	}
	else if(c2 == false){
		if(x1 < x2){
			WindowDrawLine(w, (int)((y - offset1)/coef1), y, x2, y, couleur_r, couleur_g, couleur_b);
		}
		else{
			WindowDrawLine(w, x2, y, (int)((y - offset1)/coef1), y, couleur_r, couleur_g, couleur_b);
		}
	}
	else{
		if(x1 > x2){
			WindowDrawLine(w, (int)((y - offset2)/coef2), y, (int)((y - offset1)/coef1), y, couleur_r, couleur_g, couleur_b);
		}
		else{
			WindowDrawLine(w, (int)((y - offset1)/coef1), y, (int)((y - offset2)/coef2), y, couleur_r, couleur_g, couleur_b);
		}
	}
}
for (int y = y2; y <= y3; y++){
	if ((c1 == false) && (c3 == false)){
		WindowDrawPoint(w, x1, y, couleur_r, couleur_g, couleur_b);
	} 
	else if(c1 == false){
		if (x1 < x3) {
			WindowDrawLine(w, x1, y, (int)((y - offset3)/coef3), y, couleur_r, couleur_g, couleur_b);
		}
		else {
			WindowDrawLine(w, (int)((y - offset3)/coef3), y, x1, y, couleur_r, couleur_g, couleur_b);
		}
	}
	else if(c3 == false){
		if (x1 < x3){
			WindowDrawLine(w, (int)((y - offset1)/coef1), y, x2, y, couleur_r, couleur_g, couleur_b);
		}
		else{
			WindowDrawLine(w, x2, y, (int)((y - offset1)/coef1), y, couleur_r, couleur_g, couleur_b);
		}
	}
	else{
		if (x1 < x3){
			WindowDrawLine(w, (int)((y - offset1)/coef1), y, (int)((y - offset3)/coef3), y, couleur_r, couleur_g, couleur_b);
		}
		else{
			WindowDrawLine(w, (int)((y - offset3)/coef3), y, (int)((y - offset1)/coef1), y, couleur_r, couleur_g, couleur_b);
		}
	} 
}
}


