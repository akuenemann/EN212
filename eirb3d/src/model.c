#include <string.h>
#include <stdio.h>
#include "model.h"

vector_t * g_vertex;
vector_t * g_norm;
vector_t * g_texcoord;
vector_t * g_face;

vector_t * ModelVertices() {
	return g_vertex;
}

vector_t * ModelNormals() {
	return g_norm;
}

vector_t * ModelTexcoords() {
	return g_texcoord;
}

vector_t * ModelFaces() {
	return g_face;
}

vec3f_t ModelGetVertex( int index ) {
	vec3f_t v = *(vec3f_t*)VectorGetFromIdx( ModelVertices(), index );
	return v;
}

vec3f_t ModelGetNormal( int index ) {
	vec3f_t t = *(vec3f_t*)VectorGetFromIdx( ModelNormals(), index );
	return t;
}

vec3f_t ModelGetTexcoord( int index ) {
	vec3f_t t = *(vec3f_t*)VectorGetFromIdx( ModelTexcoords(), index );
	return t;
}

face_t ModelGetFace( int index ) {
	face_t f = *(face_t*)VectorGetFromIdx( ModelFaces(), index );
	return f;
}

bool ModelLoad( char * objfilename ) {

	g_vertex = Vector();
	g_norm = Vector();
	g_texcoord = Vector();
	g_face = Vector();

	char ligne[128];
	char str[8];
	FILE *modele = fopen(objfilename,"r");
	if( modele == NULL ) {
		printf( "erreur d'ouverture du fichier\n" );
	}
while(feof(modele)==0){
  fgets(ligne, 128, modele);
	//printf("LIGNE : %s\n", ligne);

		int ok = sscanf( ligne, "%s", str );
		//printf("ok : %d\n", ok);
		if ( strcmp(str,"v") == 0 ){
			vec3f_t * v1 = (vec3f_t*)malloc( sizeof( vec3f_t ) );
			int okv = sscanf(ligne, " %s %f %f %f", str, &v1->x, &v1->y, &v1->z );
			//printf("okv : %d\n", okv);
			//printf("ligne v : %s %f %f %f\n", str, v1->x, v1->y, v1->z);
			VectorAdd( g_vertex,  v1 );
		}
		else if( strcmp(str,"vn") == 0 ){
			vec3f_t * v2 = (vec3f_t*)malloc( sizeof( vec3f_t ) );
			int okvn = sscanf(ligne, "%s %f %f %f\n", str, &v2->x, &v2->y, &v2->z );
			//printf("okvn : %d\n", okvn);
			VectorAdd( g_norm,  v2 );
			//printf("ligne vn : %s %f %f %f\n", str, v2->x, v2->y, v2->z);
		}
		else if(strcmp(str,"vt") == 0){

			vec2f_t * u = (vec2f_t*)malloc( sizeof( vec2f_t ) );
			int okvt = sscanf(ligne, "%s %f %f", str, &u->x, &u->y );
			//printf("okvt : %d\n", okvt);
			VectorAdd (g_texcoord,  u);
			//printf("ligne vt : %s %f %f\n", str, u->x, u->y);

		}
		else if(strcmp(str,"f") == 0){

			face_t * face = (face_t*)malloc( sizeof( face_t ) );
			sscanf(ligne, "%s %d/%d/%d %d/%d/%d %d/%d/%d", str, &face->v[0], &face->vn[0], &face->vt[0], &face->v[1], &face->vn[1], &face->vt[1], &face->v[2], &face->vn[2], &face->vt[2]);
			VectorAdd(g_face, face);
			//printf("ligne f : %s %d/%d/%d %d/%d/%d %d/%d/%d\n", str, face->v[0], face->vn[0], face->vt[0], face->v[1], face->vn[1], face->vt[1], face->v[2], face->vn[2], face->vt[2]);

		}
}
	fclose(modele);
	return true;
}
