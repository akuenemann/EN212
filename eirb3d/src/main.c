﻿#include "window.h"
#include "events.h"
#include "vector.h"
#include "geometry.h"
#include "model.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


int main( int argc, char ** argv ) {

	const int width		= 512;
	const int height	= 512;

	bool test = ModelLoad("./bin/data/head.obj");

	// Ouverture d'une nouvelle fenêtre
	window_t * mainwindow = WindowInit( width, height, 4 );
	

	int done = false;

	// Tant que l'utilisateur de ferme pas la fenêtre
	while ( !done ) {

		// Mise à jour et traitement des evênements de la fenêtre
		done = EventsUpdate( mainwindow );		
		
		// Effacement de l'écran avec une couleur
		WindowDrawClearColor( mainwindow, 0, 0, 0 );

		// Dessin d'un point blanc au milieu de le fenêtre		
		//WindowDrawPoint( mainwindow, width / 2, height / 2, 255, 255, 255 );

		// Dessin d'une ligne
		//for(int i = 0 ; i < 10000 ; i++){
			//WindowDrawLine( mainwindow, 615, 163, 612, 289, 255, 255, 255);
			//WindowDrawLine( mainwindow, 265, 315, 612, 289, 255, 255, 255);
			//WindowDrawLine( mainwindow, 615, 163, 265, 315, 255, 255, 255);
		//}
		for (int i=0 ; i < VectorGetLength( ModelFaces() ); i++){
			WindowDrawTriangle(mainwindow, i);
			
		}
		SDL_Delay(100);
		
		//WindowDrawTriangle(mainwindow, 19);
		
		// Mise à jour de la fenêtre
		WindowUpdate( mainwindow );

	}

	// Fermeture de la fenêtre
	WindowDestroy( mainwindow );
	
	
	free(ModelNormals());
	free(ModelVertices());
	free(ModelTexcoords());
	free(ModelFaces());
	
	return 1;
}
