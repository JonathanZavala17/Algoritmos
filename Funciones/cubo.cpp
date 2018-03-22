#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
 
//Definimos variables
double rotate_y=0;
double rotate_x=0;
double rotate_z=0;

float x =0.0;
float y =0.0; 
GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.0f;
GLfloat scale = 1.0f;
 
GLint ancho = 800;
GLint alto = 600;
int perpectiva = 0;
 
//para mas puntos
void punto(float x, float y)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
    glPointSize(20);
    
    glBegin(GL_POINTS);
    // puntos en pantallas
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(0.0f,0.0f,0.0f);
    
    glEnd();
    glFlush();
    glutSwapBuffers();
    
}

void punto1(float x, float y)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
    glPointSize(20);
    
    glBegin(GL_POINTS);
    // puntos en pantallas
    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f(0.5f,0.5f,0.0f);
    
    glEnd();
    glFlush();
    glutSwapBuffers();
    
}
void tetera(float x, float y)
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(0.0,1.0,1.0);
    glLoadIdentity();
    glScalef (1.0, 2.0, 1.0);
    //glutWireSphere(0.8, 100, 100);
    //glutSolidSphere(0.8, 10, 10);
    //glutWireCube(2.0f);
    //glutSolidCube(2.0f);
    //glutWireTorus(0.5,1.0,20,20);
    //glutSolidTorus(0.5,1.0,20,20);
    //glutWireCone(1,1,10,10);    
    //glutSolidCone(1,1,10,10);
    glutWireTeapot(1.0);
    //glutSolidTeapot(1.0);

    glTranslatef(X, Y, Z); 	// Transladar en los 3 ejes
    // Otras transformaciones
    glScalef(scale, scale, scale);
    
    
    
    glFlush();
    glutSwapBuffers();
    
}

void tetra(float x, float y)
{
    //  Borrar pantalla y Z-buffer
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(0.0,1.0,1.0);
    glLoadIdentity();
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    glRotatef( rotate_z, 0.0, 0.0, 1.0 );
    //gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glScalef (1.0, 2.0, 1.0);
    //glutWireSphere(0.8, 100, 100);
    //glutSolidSphere(0.8, 10, 10);
    //glutWireCube(2.0f);
    //glutSolidCube(2.0f);
    //glutWireTorus(0.5,1.0,20,20);
    //glutSolidTorus(0.5,1.0,20,20);
    //glutWireCone(1,1,10,10);    
    //glutSolidCone(1,1,10,10);
    //glutWireTeapot(1.0);
    //glutSolidTeapot(1.0);
    //glutWireDodecahedron();
    //glutSolidDodecahedron();
    //glutWireOctahedron();
    //glutSolidOctahedron();
    //glutWireIcosahedron();
    //glutSolidIcosahedron();
    glutWireTetrahedron();
    //glutSolidTetrahedron();



    glTranslatef(X, Y, Z); 	// Transladar en los 3 ejes
    // Otras transformaciones
    glScalef(scale, scale, scale);
    glFlush();
	
	
    
    glutSwapBuffers();
 
}
//declaracion del menu
void menu(int valor){
if(valor == 1)
 {
punto (0,0);
}
if(valor == 2)
 {
punto1(0,0);
}
if(valor == 3)
{
exit(0);
}
if(valor == 4)
{
tetera(0,0);
}
if(valor == 5)
{
tetra(0,0);
}
glutPostRedisplay();
glFlush();

}


//declaracion del menu
void menu_opciones(void)
{
glutCreateMenu(menu);
glutAddMenuEntry("Dubujo 1", 1);
glutAddMenuEntry("Dubujo 2", 2);
glutAddMenuEntry("Salir", 3);
glutAddMenuEntry("Tetera", 4);
glutAddMenuEntry("Tetra", 5);
glutAttachMenu(GLUT_RIGHT_BUTTON); // elegir tecla
}
 void reshape(int w, int h)
 {
	 glViewport(0, 0,(GLsizei) w,(GLsizei) h);
	 glMatrixMode(GL_PROJECTION);
	 menu_opciones();
         glLoadIdentity();
	 if(perpectiva)
	   gluPerspective(45.0f, (GLfloat)w/(GLfloat)h, 0.2f, 30.0f);
	
	 else
	 //glOrtho(-4,4,-4,4,-4,4);
	 glOrtho(-5,5,-5,5,-5,5);
	 //glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
	 glMatrixMode(GL_MODELVIEW);
	 
	 ancho = w;
	 alto = h;
 }

 
void display(void)
{

//punto(0,0);
//punto1(0,0);

/*    //  Borrar pantalla y Z-buffer
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(0.0,1.0,1.0);
    glLoadIdentity();
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    glRotatef( rotate_z, 0.0, 0.0, 1.0 );
    //gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glScalef (1.0, 2.0, 1.0);
    //glutWireSphere(0.8, 100, 100);
    //glutSolidSphere(0.8, 10, 10);
    //glutWireCube(2.0f);
    //glutSolidCube(2.0f);
    //glutWireTorus(0.5,1.0,20,20);
    //glutSolidTorus(0.5,1.0,20,20);
    glutWireCone(1,1,10,10);    
    //glutSolidCone(1,1,10,10);



    glTranslatef(X, Y, Z); 	// Transladar en los 3 ejes
    // Otras transformaciones
    glScalef(scale, scale, scale);
    */glFlush();
	
	
    
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
 
void init()
{
	glClearColor(0,0,0,0);
	//habitar la prueba de profundidad de z-buffer
	glEnable(GL_DEPTH_TEST);
	ancho = 800;
	alto = 600;
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
   
    case 'p':
		perpectiva=1;
		reshape(ancho,alto);
		break;
	case 'o':
   
		perpectiva=0;
		reshape(ancho,alto);
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
    glutCreateWindow("Cubo controlado por teclas");
 
    // Habilitar la prueba de profundidad de Z-buffer
    glEnable(GL_DEPTH_TEST);
	init();
	glutReshapeFunc(reshape);
	
    // Funciones de retrollamada
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
 
    // Pasar el control de eventos a GLUT
    glutMainLoop();
 
    // Regresar al sistema operativo
    return 0;
 
}


