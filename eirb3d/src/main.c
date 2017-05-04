#include "window.h"
#include "events.h"
#include "vector.h"
#include "geometry.h"
#include "model.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main( int argc, char ** argv ) {

	const int width		= 1024;
	const int height	= 768;

	bool test = ModelLoad("./bin/data/body.obj");

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
			//WindowDrawLine( mainwindow, 50, 10, 50, 200, 255, 255, 255);
		//}
		
		WindowDrawTriangle(mainwindow, 1);
		
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
