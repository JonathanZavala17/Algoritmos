#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <SOIL/SOIL.h>

GLuint texture[0];

//Definimos variables
double rotate_y=0;
double rotate_x=0;
double rotate_z=0;


float w=0;
float h=0;
float w1=0;
float h1=0;
 


GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.0f;
GLfloat scale = 1.0f;
 
 
GLint ancho = 800;
GLint alto = 600;
int perpectiva = 0;
 
 
 


 void reshape(int w, int h)
 {
	 glViewport(0, 0,(GLsizei) w,(GLsizei) h);
	 glMatrixMode(GL_PROJECTION);
	 glLoadIdentity();
	/* if(perpectiva)
	   gluPerspective(45.0f, (GLfloat)w/(GLfloat)h, 0.2f, 30.0f);
	
	 else*/
	 //glOrtho(-4,4,-4,4,-4,4);
	 glOrtho(-170 ,100,-100,150,-170,170);
	 //glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
	 glMatrixMode(GL_MODELVIEW);
	 
	 ancho = w;
	 alto = h;
 }


void Estadio()
{
    //  Borrar pantalla y Z-buffer
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    //glColor3f(0.0,1.0,1.0);
    // Resetear transformaciones
    glLoadIdentity();
    gluLookAt (4, 2, 3, 0, 0, 0, 0.0,1.0,0.0);
    glScalef (1.0, 2.0, 1.0);
   // gluLookAt (4, 2, 3, 0, 0, 0, 0.0,1.0,0.0);
    // Rotar en el eje X,Y y Z
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    glRotatef( rotate_z, 0.0, 0.0, 1.0 );
    glTranslatef(X, Y, Z); 	// Transladar en los 3 ejes
    // Otras transformaciones
    glScalef(scale, scale, scale);
    // Primera cara, se identica por multiples colores
     glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    
    //CAMPO DE LA CANCHA
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_QUADS);
	glVertex3f(-60.0f,0.0f,0.0f);	
	glVertex3f(60.0f,0.0f,0.0f);
	glVertex3f(60.0f,0.0f,90.0f);
	glVertex3f(-60.0f,0.0f,90.0f);		
	glEnd();


	//CONTORNO FUERA DEL CAMPO 
	glColor3f(0.0,0.6,0.0);
	glBegin(GL_QUADS);
	glVertex3f(-75.0f,-0.1f,-15.0f);	
	glVertex3f(75.0f,-0.1f,-15.0f);
	glVertex3f(75.0f,-0.1f,105.0f);
	glVertex3f(-75.0f,-0.1f,105.0f);		
	glEnd();



	//VALLAS derecha inferior (POSIBLE TEXTURA)
	glColor3f(1.0,0.6,0.0);
	glBegin(GL_QUADS);
	glVertex3f(-75.0f,-0.1f,-15.0f);	
	glVertex3f(75.0f,-0.1f,-15.0f);
	glVertex3f(75.0f,2.0f,-15.0f);
	glVertex3f(-75.0f,2.0f,-15.0f);		
	glEnd();
	
	//pasillo inferior derecho
	glColor3f(0.43,0.43,0.43);
	glBegin(GL_QUADS);
	glVertex3f(-75.0f,-0.1f,-15.0f);	
	glVertex3f(75.0f,-0.1f,-15.0f);
	glVertex3f(75.0f,-0.1f,-20.0f);
	glVertex3f(-75.0f,-0.1f,-20.0f);		
	glEnd();
	
	//tope del pasillo inferior derecho
	glColor3f(0.43,0.43,0.43);
	glBegin(GL_QUADS);
	glVertex3f(-75.0f,-0.1f,-15.0f);	
	glVertex3f(-75.0f,5.0f,-15.0f);
	glVertex3f(-75.0f,5.0f,-24.8f);
	glVertex3f(-75.0f,-0.1f,-20.0f);		
	glEnd();
	
	//pasillo inferior izquierdo
	glColor3f(0.43,0.43,0.43);
	glBegin(GL_QUADS);
	glVertex3f(-75.0f,5.0f,105.0f);	
	glVertex3f(-80.0f,5.0f,105.0f);
	glVertex3f(-80.0f,5.0f,-24.8f);
	glVertex3f(-75.0f,5.0f,-24.8f);		
	glEnd();
	
	//tope del pasillo inferior izquierdo
	glColor3f(0.43,0.43,0.43);
	glBegin(GL_QUADS);
	glVertex3f(-75.0f,-0.1f,-15.0f);	
	glVertex3f(-75.0f,5.0f,-15.0f);
	glVertex3f(-75.0f,5.0f,-24.8f);
	glVertex3f(-75.0f,-0.1f,-20.0f);		
	glEnd();



	//VALLAS izquierda inferior (POSIBLE TEXTURA) 
	glColor3f(1.0,0.6,0.0);
	glBegin(GL_QUADS);
	glVertex3f(-75.0f,-0.1f,0.0f);	
	glVertex3f(-75.0f,-0.1f,90.0f);
	glVertex3f(-75.0f,5.0f,90.0f);
	glVertex3f(-75.0f,5.0f,0.0f);		
	glEnd();



	//Suelo
	glColor3f(0.0,1.0,1.0);
	glBegin(GL_QUADS);
	glVertex3f(-120.0f,-0.2f,105.0f);
	glVertex3f(-120.0f,-0.2f,-15.0f);
	glVertex3f(-75.0f,-0.20f,-15.0f);
	glVertex3f(-75.0f,-0.20,105.0f);
	glEnd();

	//Suelo completo
	glColor3f(0.43,0.43,0.43);
	glBegin(GL_QUADS);
	glVertex3f(-120.0f,-0.21f,105.0f);
	glVertex3f(-120.0f,-0.21f,-60.0f);
	glVertex3f(75.0f,-0.21f,-60.0f);
	glVertex3f(75.0f,-0.21,105.0f);
	glEnd();


//############### Gradas Derechas  Abajo #################################################################################################################################
	
	//Altura del barandal derecho
	glColor3f(0.43,0.0,0.43);
	glBegin(GL_QUADS);
	glVertex3f(75.0f,-0.1f,-20.0f);
	glVertex3f(75.0f,1.51f,-20.0f);
	glVertex3f(-75.0f,1.5f,-20.0f);
	glVertex3f(-75.0f,-0.1,-20.0f);
	glEnd();


	//Gradas Derechas TEXTURA
	glColor3f(1.0,0.43,0.43);
	glBegin(GL_QUADS);
	glVertex3f(75.0f,12.5f,-35.0f);
	glVertex3f(75.0f,1.5f,-20.0f);
	glVertex3f(-80.0f,1.5f,-20.0f);
	glVertex3f(-95.0f,12.5,-35.0f);
	glEnd();
	
	
//############## Gradas Izquierdas Abajo ##############################################################################################################################


	
	//Gradas izquierdas (TEXTURA) 
	glColor3f(1.0,0.43,0.43);
	glBegin(GL_POLYGON);
	glVertex3f(-95.0f,12.5f,105.0f);
	glVertex3f(-80.0f,5.0f,105.0f);
	glVertex3f(-80.0f,5.0f,-24.8f);
	glVertex3f(-95.0f,12.5f,-35.0f);
	glEnd();



	//Altura del barandal izquerdo
	glColor3f(0.43,0.0,0.43);
	glBegin(GL_QUADS);
	glVertex3f(-75.0f,5.0f,105.0f);
	glVertex3f(-75.0f,6.0f,105.0f);
	glVertex3f(-75.0f,6.0f,-24.8f);
	glVertex3f(-75.0f,5.0f,-24.8f);
	
	glVertex3f(-74.999f,-0.1f,-19.0f);
	glVertex3f(-74.999f,3.0f,-19.0f);
	glVertex3f(-74.999f,6.5f,-24.8f);
	glVertex3f(-74.999f,-0.1f,-24.8f);
	
	glEnd();
	//Topes de baranda izquierda
	
	glBegin(GL_POLYGON);
	
	glVertex3f(-74.999f,-0.1,105.1f);
	glVertex3f(-74.999f,6.0f,105.1f);
	glVertex3f(-80.0f,6.0f,105.1f);
	glVertex3f(-95.0f,14.5f,105.1f);
	glVertex3f(-95.0f,-0.1f,105.1f);
	glVertex3f(-80.0f,-0.1f,105.1f);
	
	glEnd();

    //Tope de baranda derecha
	glBegin(GL_POLYGON);
	
	glVertex3f(75.0999f,-0.1,-15.0f);
	glVertex3f(75.0999f,2.0f,-15.0f);
	glVertex3f(75.0999f,2.0f,-20.0f);
	glVertex3f(75.0999f,14.5f,-35.0f);
	glVertex3f(75.0999f,-0.1f,-35.0f);
	glVertex3f(75.0999f,-0.1f,-20.0f);
	glEnd();


	//Topes rectangulares de izquierda y derecha respectivo
	glBegin(GL_QUADS);
	
	glVertex3f(-95.0f,-0.1f,105.1f);
	glVertex3f(-95.0f,14.5f,105.1f);
	glVertex3f(-100.0f,14.5f,105.1f);
	glVertex3f(-100.0f,-0.1f,105.1f);
	
	glVertex3f(75.0999f,-0.1,-35.0f);
	glVertex3f(75.0999f,14.5f,-35.0f);
	glVertex3f(75.0999f,14.5f,-40.0f);
	glVertex3f(75.0999f,0.1f,-40.0f);
	
	glEnd();

	
	//PARED DE GRADAS IZQUIERDAS 1
	glColor3f(0.43,0.43,0.43);
	glBegin(GL_POLYGON);
	glVertex3f(-75.0f,-0.1f,90.0f);
	glVertex3f(-80.0f,-0.1f,90.0f);
	glVertex3f(-95.0f,-0.1f,90.0f);
	glVertex3f(-95.0f,12.5f,90.0f);
	glVertex3f(-80.0f,5.0f,90.0f);
	glVertex3f(-75.0f,5.0f,90.0f);
	
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(-95.0f,12.5f,90.0f);
	glVertex3f(-120.0f,12.5f,90.0f);
	glVertex3f(-120.0f,-0.1f,90.0f);
	glVertex3f(-95.0f,-0.1f,90.0f);
	
	
	glEnd();

	//PARED DE GRADAS IZQUIERDAS 2
	glColor3f(0.43,0.43,0.43);
	glBegin(GL_POLYGON);
	glVertex3f(-75.0f,-0.1f,0.0f);
	glVertex3f(-80.0f,-0.1f,0.0f);
	glVertex3f(-95.0f,-0.1f,0.0f);
	glVertex3f(-95.0f,12.5f,0.0f);
	glVertex3f(-80.0f,5.0f,0.0f);
	glVertex3f(-75.0f,5.0f,0.0f);
	
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(-95.0f,12.5f,0.0f);
	glVertex3f(-120.0f,12.5f,0.0f);
	glVertex3f(-120.0f,-0.1f,0.0f);
	glVertex3f(-95.0f,-0.1f,0.0f);
	
	
	glEnd();

	
	//PARED DE GRADAS IZQUIERDAS 3
	glColor3f(0.43,0.43,0.43);
	glBegin(GL_POLYGON);
	glVertex3f(-75.0f,-0.1f,-15.0f);
	glVertex3f(-80.0f,-0.1f,-15.0f);
	glVertex3f(-95.0f,-0.1f,-15.0f);
	glVertex3f(-95.0f,12.5f,-15.0f);
	glVertex3f(-80.0f,5.0f,-15.0f);
	glVertex3f(-75.0f,5.0f,-15.0f);
	
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(-95.0f,12.5f,-15.0f);
	glVertex3f(-120.0f,12.5f,-15.0f);
	glVertex3f(-120.0f,-0.1f,-15.0f);
	glVertex3f(-95.0f,-0.1f,-15.0f);
	
	
	glEnd();


	//PARED DE GRADAS IZQUIERDAS 4
	glColor3f(0.43,0.43,0.43);
	glBegin(GL_POLYGON);
	glVertex3f(-75.0f,-0.1f,105.0f);
	glVertex3f(-80.0f,-0.1f,105.0f);
	glVertex3f(-95.0f,-0.1f,105.0f);
	glVertex3f(-95.0f,12.5f,105.0f);
	glVertex3f(-80.0f,5.0f,105.0f);
	glVertex3f(-75.0f,5.0f,105.0f);
	
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(-95.0f,12.5f,105.0f);
	glVertex3f(-120.0f,12.5f,105.0f);
	glVertex3f(-120.0f,-0.1f,105.0f);
	glVertex3f(-95.0f,-0.1f,105.0f);
	
	
	glEnd();
	

//###### Palcos Izquierdos Y Derechos ############################################################################################################################################

	//Parte de arriba 1
	glColor3f(0.43,1.0,0.43);
	glBegin(GL_QUADS);
	//HACER HUECOS
	glVertex3f(-100.0f,17.5f,105.0f);
	glVertex3f(-100.0f,12.5f,105.0f);
	glVertex3f(-100.0f,12.5f,-40.0f);
	glVertex3f(-100.0f,17.5f,-40.0f);
	
	//(TEXTURA)
	glColor3f(0.43,0.43,1.0);
	glVertex3f(-100.0f,17.5f,105.0f);
	glVertex3f(-100.0f,22.5f,105.0f);
	glVertex3f(-100.0f,22.5f,-40.0f);
	glVertex3f(-100.0f,17.5f,-40.0f);
	
	glEnd();
	
	//Barandas superiores
	glColor3f(0.43,0.0,0.43);
	glBegin(GL_QUADS);
	glVertex3f(-100.0f,24.5f,105.0f);
	glVertex3f(-100.0f,22.5f,105.0f);
	glVertex3f(-100.0f,22.5f,-40.0f);
	glVertex3f(-100.0f,24.5f,-40.0f);
	
	glVertex3f(-100.0f,24.5f,-40.0f);
	glVertex3f(-100.0f,22.5f,-40.0f);
	glVertex3f(75.0f,22.5f,-40.0f);
	glVertex3f(75.0f,24.5f,-40.0f);
	glEnd();
	


//####################################################################################################################################################


	//Parte de arriba 1
	glColor3f(0.43,1.0,0.43);
	glBegin(GL_QUADS);
	//HACER HUECOS
	glVertex3f(-100.0f,17.5f,-40.0f);
	glVertex3f(-100.0f,12.5f,-40.0f);
	glVertex3f(74.99999f,12.5f,-40.0f);
	glVertex3f(74.99999f,17.5f,-40.0f);
	
	//(TEXTURA)
	glColor3f(0.43,0.43,1.0);
	glVertex3f(-100.0f,17.5f,-40.0f);
	glVertex3f(-100.0f,22.5f,-40.0f);
	glVertex3f(74.99999f,22.5f,-40.0f);
	glVertex3f(74.99999f,17.5f,-40.0f);
	
	glEnd();
	

	//Gradas parte de caminar derecha
	glColor3f(0.43,0.43,0.43);
	glBegin(GL_QUADS);
	glVertex3f(-100.0f,12.5f,-40.0f);
	glVertex3f(-100.0f,12.5f,-35.0f);
	glVertex3f(75.0f,12.5f,-35.0f);
	glVertex3f(75.0f,12.5f,-40.0f);
	
	glEnd();

		
	//Gradas parte de caminar izquierda 
	glColor3f(0.43,0.43,0.43);
	glBegin(GL_QUADS);
	glVertex3f(-95.0f,12.5f,105.0f);
	glVertex3f(-100.0f,12.5f,105.0f);
	glVertex3f(-100.0f,12.5f,-40.0f);
	glVertex3f(-95.0f,12.5f,-40.0f);
	
	
	glEnd();
	
	
//### 	PLANTA SUPERIOR  ##########################################################################################################################################


	//Gradas parte de caminar derecha
	glColor3f(0.43,0.43,0.43);
	glBegin(GL_QUADS);
	glVertex3f(-105.0f,22.5f,-40.0f);
	glVertex3f(-105.0f,22.5f,-45.0f);
	glVertex3f(75.0f,22.5f,-45.0f);
	glVertex3f(75.0f,22.5f,-40.0f);
	
	//Gradas parte de caminar izquierda 
	glVertex3f(-100.0f,22.5f,105.0f);
	glVertex3f(-105.0f,22.5f,105.0f);
	glVertex3f(-105.0f,22.5f,-40.0f);
	glVertex3f(-100.0f,22.5f,-40.0f);
	
	glEnd();
 
	//Baranda abajo superior izquierda
	glColor3f(0.43,0.0,0.43);
	glBegin(GL_QUADS);
	glVertex3f(-105.0f,22.5f,105.0f);
	glVertex3f(-105.0f,23.5f,105.0f);
	glVertex3f(-105.0f,23.5f,-45.0f);
	glVertex3f(-105.0f,22.5f,-45.0f);
	
	glVertex3f(-74.999f,-0.1f,-19.0f);
	glVertex3f(-74.999f,3.0f,-19.0f);
	glVertex3f(-74.999f,6.5f,-24.8f);
	glVertex3f(-74.999f,-0.1f,-24.8f);
	glEnd();
	
	//Baranda abajo superior derecho
	glColor3f(0.43,0.0,0.43);
	glBegin(GL_QUADS);
	
	glVertex3f(75.0f,22.5f,-45.0f);
	glVertex3f(75.0f,23.5f,-45.0f);
	glVertex3f(-105.0f,23.5f,-45.0f);
	glVertex3f(-105.0f,22.5,-45.0f);
	
	glEnd();
	
	
	//Topes de baranda izquierda
	
	glBegin(GL_POLYGON);
	
	glVertex3f(-74.999f,-0.1,105.1f);
	glVertex3f(-74.999f,6.0f,105.1f);
	glVertex3f(-80.0f,6.0f,105.1f);
	glVertex3f(-95.0f,14.5f,105.1f);
	glVertex3f(-95.0f,-0.1f,105.1f);
	glVertex3f(-80.0f,-0.1f,105.1f);
	
	glEnd();





	//Tope de baranda derecha
	
       
	texture[0] = SOIL_load_OGL_texture // cargamos la imagen
                     (
                "textura.jpg",
                SOIL_LOAD_AUTO,
                SOIL_CREATE_NEW_ID,
                SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                     );
     glEnable(GL_TEXTURE_2D);

        float color[] = { 1.0f, 0.0f, 0.0f, 1.0f };
        glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, color);
        glBindTexture(GL_TEXTURE_2D, texture[0]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        //glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
        //glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
        //glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);

    
	glBegin(GL_POLYGON);
	glColor3f(1.0,1.0,1.0);
	glTexCoord3f(75.1f,-0.1,-15.0f); glVertex3f(75.1f,-0.1,-15.0f);
	glTexCoord3f(75.1f,2.0,-15.0f); glVertex3f(75.1f,2.0f,-15.0f);
	glTexCoord3f(75.1f,2.0,-20.0f); glVertex3f(75.1f,2.0f,-20.0f);
	glTexCoord3f(75.1f,14.5,-35.0f); glVertex3f(75.1f,14.5f,-35.0f);
	glTexCoord3f(75.1f,-0.1,-35.0f); glVertex3f(75.1f,-0.1f,-35.0f);
	//glTexCoord3f(75.0999f,-0.1,-20.0f); glVertex3f(75.0999f,-0.1f,-20.0f);

	//Topes rectangulares de izquierda y derecha respectivo
	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,1.0);
	glTexCoord3f(75.11f,-0.1,-35.0f); glVertex3f(75.11f,-0.1,-35.0f);
	glTexCoord3f(75.11f,14.5,-35.0f); glVertex3f(75.11f,14.5f,-35.0f);
	glTexCoord3f(75.11f,14.5,-40.0f); glVertex3f(75.11f,14.5f,-40.0f);
	glTexCoord3f(75.11f,-0.1,-40.0f); glVertex3f(75.11f,0.1f,-40.0f);
	
	
	glEnd();
	
	
	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,1.0);
	
	glTexCoord3f(-95.0f,-0.1f,105.2f); glVertex3f(-95.0f,-0.1f,105.2f);
	glTexCoord3f(-95.0f,14.5f,105.2f); glVertex3f(-95.0f,14.5f,105.2f);
	glTexCoord3f(-100.0f,14.5f,105.2f); glVertex3f(-100.0f,14.5f,105.2f);
	glTexCoord3f(-100.0f,-0.1f,105.2f); glVertex3f(-100.0f,-0.1f,105.2f);
	glEnd();



//############### Gradas Derechas e Izquierda arriba #################################################################################################################################
	


	//Gradas Derechas TEXTURA
	glColor3f(1.0,0.43,0.43);
	glBegin(GL_QUADS);
	glVertex3f(75.0f,29.5f,-60.0f);
	glVertex3f(75.0f,22.5f,-45.0f);
	glVertex3f(-105.0f,22.5f,-45.0f);
	glVertex3f(-120.0f,29.5,-60.0f);
	glEnd();
	

	
	//Gradas izquierdas (TEXTURA) 
	glColor3f(1.0,0.43,0.43);
	glBegin(GL_POLYGON);
	glVertex3f(-120.0f,29.5f,105.0f);
	glVertex3f(-105.0f,22.5f,105.0f);
	glVertex3f(-105.0f,22.5f,-45.0f);
	glVertex3f(-120.0f,29.5f,-60.0f);
	glEnd();


	//Baranda abajo superior izquierda
	glColor3f(0.43,0.0,0.43);
	glBegin(GL_QUADS);
	glVertex3f(-120.0f,29.5f,105.0f);
	glVertex3f(-120.0f,32.5f,105.0f);
	glVertex3f(-120.0f,32.5f,-60.0f);
	glVertex3f(-120.0f,29.5f,-60.0f);
	
	glEnd();
	
	//Baranda abajo superior derecho
	glColor3f(0.43,0.0,0.43);
	glBegin(GL_QUADS);
	
	glVertex3f(75.0f,29.5f,-60.0f);
	glVertex3f(75.0f,32.5f,-60.0f);
	glVertex3f(-120.0f,32.5f,-60.0f);
	glVertex3f(-120.0f,29.5,-60.0f);
	
	glEnd();





	//Topes de baranda izquierda
	
	glBegin(GL_POLYGON);
	
	glVertex3f(-100.f,-0.1,105.1f);
	glVertex3f(-100.0f,24.5f,105.0f);
	glVertex3f(-120.0f,32.5f,105.0f);
	glVertex3f(-120.0f,-0.1f,105.1f);
	
	glEnd();

    //Tope de baranda derecha
	glBegin(GL_POLYGON);
	
	glVertex3f(75.0f,-0.1,-40.0f);
	glVertex3f(75.0f,24.5f,-40.0f);
	glVertex3f(75.0f,32.5f,-60.f);
	glVertex3f(75.0f,-0.1f,-60.0f);
	glEnd();


	//Topes rectangulares de izquierda y derecha respectivo
	glBegin(GL_QUADS);
	
	glVertex3f(-100.0f,-0.1f,105.1f);
	glVertex3f(-100.0f,24.5f,105.0f);
	glVertex3f(-105.0f,24.5f,105.0f);
	glVertex3f(-105.0f,-0.1f,105.1f);
	
	glVertex3f(75.0999f,-0.1,-40.0f);
	glVertex3f(75.0999f,24.5f,-40.0f);
	glVertex3f(75.0999f,24.5f,-45.0f);
	glVertex3f(75.0999f,-0.1f,-45.0f);
	
	glEnd();




//########  Detalles internos ################################################################################################################

	glBegin(GL_QUADS);
	//Pared trasera inferior izquierda
	glColor3f(0.43,0.43,0.43);
	glVertex3f(-120.0f,12.4f,-60.0f);
	glVertex3f(-95.9f,12.4f,-60.0f);
	glVertex3f(-95.9f,12.4f,105.0f);
	glVertex3f(-120.0f,12.4f,105.0f);
	//Pared 1
	glVertex3f(-120.0f,-0.01f,-60.0f);
	glVertex3f(-120.0f,12.4f,-60.0f);
	glVertex3f(-120.0f,12.4f,-15.0f);
	glVertex3f(-120.0f,-0.1f,-15.0f);
	//Pared 2
	glVertex3f(-120.0f,-0.01f,0.0f);
	glVertex3f(-120.0f,12.4f,0.0f);
	glVertex3f(-120.0f,12.4f,90.0f);
	glVertex3f(-120.0f,-0.1f,90.0f);
	
	//Pared trasera superior izquierda
	glVertex3f(-120.0f,17.51f,-60.0f);
	glVertex3f(-100.0f,17.51f,-60.0f);
	glVertex3f(-100.0f,17.51f,105.0f);
	glVertex3f(-120.0f,17.51f,105.0f);
	//Pared 3
	glVertex3f(-120.0f,17.51f,-60.0f);
	glVertex3f(-120.0f,29.5f,-60.0f);
	glVertex3f(-120.0f,29.5f,105.1f);
	glVertex3f(-120.0f,17.51f,105.1f);

	
	glEnd();
	
	//Derecha
	glBegin(GL_QUADS);
	glVertex3f(75.0f,17.51,-60.0f);
	glVertex3f(-120.0f,17.51f,-60.0f);
	glVertex3f(-120.0f,17.51f,-44.9f);
	glVertex3f(75.0f,17.51f,-44.9f);
	
	//Parte inferior
	glVertex3f(75.0f,12.5,-60.0f);
	glVertex3f(-120.0f,12.5f,-60.0f);
	glVertex3f(-120.0f,12.5f,-40.f);
	glVertex3f(75.0f,12.5f,-40.0f);
	
	//Pared 1
	glVertex3f(75.0f,-0.1,-60.0f);
	glVertex3f(-120.0f,-0.1f,-60.0f);
	glVertex3f(-120.0f,12.5f,-60.0f);
	glVertex3f(75.0f,12.5f,-60.0f);
	
	//Pared 2
	glVertex3f(75.0f,29.5,-60.0f);
	glVertex3f(-120.0f,29.5f,-60.0f);
	glVertex3f(-120.0f,17.5f,-60.0f);
	glVertex3f(75.0f,17.5f,-60.0f);
	
	glEnd();


	
	//Pared completa
	glBegin(GL_QUADS);

	glVertex3f(75.0f,29.5,-60.00001f);
	glVertex3f(-120.0f,29.5f,-60.00001f);
	glVertex3f(-120.0f,-0.1f,-60.00001f);
	glVertex3f(75.0f,-0.1f,-60.00001f);

	glVertex3f(-120.00001f,-0.1f,-60.0f);
	glVertex3f(-120.00001f,29.5f,-60.0f);
	glVertex3f(-120.00001f,29.5f,105.1f);
	glVertex3f(-120.00001f,-0.1f,105.1f);

	
	glEnd();

//############################## Parte de arriba #######################################################################################################################
	
	//Pantalla
	glBegin(GL_QUADS);
		
	glVertex3f(-120.0f,42.5f,45.0f);
	glVertex3f(-120.0f,33.5f,45.0f);
	glVertex3f(-120.0f,33.5f,10.0f);
	glVertex3f(-120.0f,42.5f,10.0f);
	
	glEnd();
	
	//Soportes de pantalla
	
	glLineWidth(3.5);
	glBegin(GL_LINES);
	glVertex3f(-120.6f,42.5f,45.0f);
	glVertex3f(-120.6f,29.0f,45.0f);
	glVertex3f(-120.6f,29.0f,10.0f);
	glVertex3f(-120.6f,42.5f,10.0f);
	glEnd();
	
	
	
	
	//Techo
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_QUADS);
	glVertex3f(75.0f,50.5f,-30.0f);
	glVertex3f(75.0f,44.0f,-70.0f);
	glVertex3f(-130.0f,44.0f,-70.0f);
	glVertex3f(-90.0f,50.5f,-30.0f);
		
	glVertex3f(-90.0f,50.5f,105.0f);
	glVertex3f(-130.0f,44.0f,105.0f);
	glVertex3f(-130.0f,44.0f,-70.0f);
	glVertex3f(-90.0f,50.5f,-30.0f);
	
	glEnd();


	//Soportes
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3f(1.0,0.0,0.0);	
	glVertex3f(70.0f,43.5f,-65.5f);
	glVertex3f(70.0f,-0.1f,-65.5f);
	glVertex3f(40.0f,43.5f,-65.5f);
	glVertex3f(40.0f,-0.1f,-65.5f);
	glVertex3f(10.0f,43.5f,-65.5f);
	glVertex3f(10.0f,-0.1f,-65.5f);
	glVertex3f(-20.0f,43.5f,-65.5f);
	glVertex3f(-20.0f,-0.1f,-65.5f);
	glVertex3f(-50.0f,43.5f,-65.5f);
	glVertex3f(-50.0f,-0.1f,-65.5f);
	glVertex3f(-80.0f,43.5f,-65.5f);
	glVertex3f(-80.0f,-0.1f,-65.5f);
	
	
	
	glVertex3f(-125.0f,43.5f,100.0f);
	glVertex3f(-125.0f,-0.1f,100.0f);
	glVertex3f(-125.0f,43.5f,70.0f);
	glVertex3f(-125.0f,-0.1f,70.0f);
	glVertex3f(-125.0f,43.5f,40.0f);
	glVertex3f(-125.0f,-0.1f,40.0f);
	glVertex3f(-125.0f,43.5f,10.0f);
	glVertex3f(-125.0f,-0.1f,10.0f);
	glVertex3f(-125.0f,43.5f,-20.0f);
	glVertex3f(-125.0f,-0.1f,-20.0f);
	

	//Dos circulares
	glVertex3f(-110.0f,43.0f,-65.5f);
	glVertex3f(-110.0f,-0.1f,-65.5f);
	
	glVertex3f(-125.0f,43.0f,-50.0f);
	glVertex3f(-125.0f,-0.1f,-50.0f);
	
	
	glEnd();

	//Vigas derechas
	glLineWidth(10);
	glBegin(GL_POLYGON);
	glColor3f(0.43,0.43,0.43);	
	glVertex3f(68.0f,50.0f,-30.0f);
	glVertex3f(68.0f,44.0f,-67.0f);
	glVertex3f(68.0f,43.0f,-67.0f);
	glVertex3f(72.0f,43.0f,-67.0f);
	glVertex3f(72.0f,44.0f,-67.0f);
	glVertex3f(72.0f,50.0f,-30.5f);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.43,0.43,0.43);	
	glVertex3f(38.0f,50.0f,-30.0f);
	glVertex3f(38.0f,44.0f,-67.0f);
	glVertex3f(38.0f,43.0f,-67.0f);
	glVertex3f(42.0f,43.0f,-67.0f);
	glVertex3f(42.0f,44.0f,-67.0f);
	glVertex3f(42.0f,50.0f,-30.5f);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.43,0.43,0.43);	
	glVertex3f(8.0f,50.0f,-30.0f);
	glVertex3f(8.0f,44.0f,-67.0f);
	glVertex3f(8.0f,43.0f,-67.0f);
	glVertex3f(12.0f,43.0f,-67.0f);
	glVertex3f(12.0f,44.0f,-67.0f);
	glVertex3f(12.0f,50.0f,-30.5f);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.43,0.43,0.43);	
	glVertex3f(-18.0f,50.0f,-30.0f);
	glVertex3f(-18.0f,44.0f,-67.0f);
	glVertex3f(-18.0f,43.0f,-67.0f);
	glVertex3f(-22.0f,43.0f,-67.0f);
	glVertex3f(-22.0f,44.0f,-67.0f);
	glVertex3f(-22.0f,50.0f,-30.5f);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.43,0.43,0.43);	
	glVertex3f(-48.0f,50.0f,-30.0f);
	glVertex3f(-48.0f,44.0f,-67.0f);
	glVertex3f(-48.0f,43.0f,-67.0f);
	glVertex3f(-52.0f,43.0f,-67.0f);
	glVertex3f(-52.0f,44.0f,-67.0f);
	glVertex3f(-52.0f,50.0f,-30.5f);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.43,0.43,0.43);	
	glVertex3f(-78.0f,50.0f,-30.0f);
	glVertex3f(-78.0f,44.0f,-67.0f);
	glVertex3f(-78.0f,43.0f,-67.0f);
	glVertex3f(-82.0f,43.0f,-67.0f);
	glVertex3f(-82.0f,44.0f,-67.0f);
	glVertex3f(-82.0f,50.0f,-30.5f);
	
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.43,0.43,0.43);	
	glVertex3f(-85.0f,50.0f,-30.0f);
	glVertex3f(-108.0f,44.0f,-67.0f);
	glVertex3f(-108.0f,43.0f,-67.0f);
	glVertex3f(-112.0f,43.0f,-67.0f);
	glVertex3f(-112.0f,44.0f,-67.0f);
	glVertex3f(-85.0f,50.0f,-30.5f);
	
	glEnd();
	
	
	
	//Izquierdos
	glBegin(GL_POLYGON);
	glColor3f(0.43,0.43,0.43);	
	glVertex3f(-90.0f,50.0f,102.0f);
	glVertex3f(-127.0f,44.0f,102.0f);
	glVertex3f(-127.0f,43.0f,102.0f);
	glVertex3f(-127.0f,43.0f,98.0f);
	glVertex3f(-127.0f,44.0f,98.0f);
	glVertex3f(-90.0f,50.0f,98.0f);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.43,0.43,0.43);	
	glVertex3f(-90.0f,50.0f,72.0f);
	glVertex3f(-127.0f,44.0f,72.0f);
	glVertex3f(-127.0f,43.0f,72.0f);
	glVertex3f(-127.0f,43.0f,68.0f);
	glVertex3f(-127.0f,44.0f,68.0f);
	glVertex3f(-90.0f,50.0f,68.0f);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.43,0.43,0.43);	
	glVertex3f(-90.0f,50.0f,42.0f);
	glVertex3f(-127.0f,44.0f,42.0f);
	glVertex3f(-127.0f,43.0f,42.0f);
	glVertex3f(-127.0f,43.0f,38.0f);
	glVertex3f(-127.0f,44.0f,38.0f);
	glVertex3f(-90.0f,50.0f,38.0f);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.43,0.43,0.43);	
	glVertex3f(-90.0f,50.0f,12.0f);
	glVertex3f(-127.0f,44.0f,12.0f);
	glVertex3f(-127.0f,43.0f,12.0f);
	glVertex3f(-127.0f,43.0f,8.0f);
	glVertex3f(-127.0f,44.0f,8.0f);
	glVertex3f(-90.0f,50.0f,8.0f);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.43,0.43,0.43);	
	glVertex3f(-90.0f,50.0f,-18.0f);
	glVertex3f(-127.0f,44.0f,-18.0f);
	glVertex3f(-127.0f,43.0f,-18.0f);
	glVertex3f(-127.0f,43.0f,-22.0f);
	glVertex3f(-127.0f,44.0f,-22.0f);
	glVertex3f(-90.0f,50.0f,-22.0f);
	
	glEnd();
	
	
		glBegin(GL_POLYGON);
	glColor3f(0.43,0.43,0.43);	
	glVertex3f(-90.0f,50.0f,-25.0f);
	glVertex3f(-127.0f,44.0f,-48.0f);
	glVertex3f(-127.0f,43.0f,-48.0f);
	glVertex3f(-127.0f,43.0f,-52.0f);
	glVertex3f(-127.0f,44.0f,-52.0f);
	glVertex3f(-90.0f,50.0f,-25.0f);
	
	glEnd();
    
    
    //## LINEAS DE LA CANCHA  #########################################################################################################################################
    
    
    
    
    
    glFlush();
    glutSwapBuffers();
 
}


void display()
{
    //  Borrar pantalla y Z-buffer
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 
    // Resetear transformaciones
    glLoadIdentity();
    Estadio();

	glEnd();



    
    glFlush();
    glutSwapBuffers();
 
}
 
 
// Función para controlar teclas especiales
void specialKeys( int key, int x, int y )
{
 
    //  Flecha derecha: aumentar rotación 7 grados
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 7;
 
    //  Flecha izquierda: rotación en eje Y negativo 7 grados
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 7;
    //  Flecha arriba: rotación en eje X positivo 7 grados
    else if (key == GLUT_KEY_UP)
        rotate_x += 7;
    //  Flecha abajo: rotación en eje X negativo 7 grados
    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 7;
    //  Tecla especial F2 : rotación en eje Z positivo 7 grados
    else if (key == GLUT_KEY_F2)
        rotate_z += 7;
    //  Tecla especial F2 : rotación en eje Z negativo 7 grados
    else if (key == GLUT_KEY_F2)
        rotate_z -= 7;
 
    //  Solicitar actualización de visualización
    glutPostRedisplay();
 
}
 
// Función para controlar teclas normales del teclado.
void keyboard(unsigned char key, int x, int y)
{
    //control de teclas que hacen referencia a Escalar y transladar el cubo en los ejes X,Y,Z.
    switch (key)
    {
    case 's':
        scale=0.5;
        break;
    case 'd':
        scale=1.5;
        break;
    case 'x' :
        X += 0.1f;
        break;
    case 'X' :
        X -= 0.1f;
        break;
    case 'y' :
        Y += 0.1f;
        break;
    case 'Y' :
        Y -= 0.1f;
        break;
    case 'z':
        Z -= 0.1f;
        break;
    case 'Z':
        Z += 0.1f;
        break;
    case 27:
        exit(0);			// exit
    }
    glutPostRedisplay();
}
 
 
 
int main(int argc, char* argv[])
{
 
    //  Inicializar los parámetros GLUT y de usuario proceso
    glutInit(&argc,argv);
 
    // Solicitar ventana con color real y doble buffer con Z-buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (800, 600);
    glutInitWindowPosition (0, 0);
    // Crear ventana
    
    glutCreateWindow("Old Trafford");
    glutReshapeFunc(reshape);    
    gluLookAt (4, 2, 3, 0, 0, 0, 0.0,1.0,0.0);
    // Habilitar la prueba de profundidad de Z-buffer
    glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
    // Funciones de retrollamada
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
 
    // Pasar el control de eventos a GLUT
    glutMainLoop();
 
    // Regresar al sistema operativo
    return 0;
 
}
