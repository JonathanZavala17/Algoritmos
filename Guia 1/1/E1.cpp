#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

float w=0;
float h=0;
void Bresenham(float w, float h)
{
	glClearColor(0,0,0,0);
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_LINES);
	glPointSize(5);
	glColor3f(0.0f,1.0f,1.0f);
	glVertex3f(-4.0f,0.0f,0.0f);
	glVertex3f(4.0f,0.0f,0.0f);
	glVertex3f(0.0f,4.0f,0.0f);
	glVertex3f(0.0f,-4.0f,0.0f);
	
        glEnd();
    
	
     
       //algoritmo 
       glBegin(GL_LINES);
       glColor3f(1.0f,1.0f,1.0f);
       //variables del algoritmo
       GLint x0,y0,x1,y1,x,y,dx,dy,p,N,NE,px,py;
	
	//limites
	x0=-4;
	y0=-4;
	x1=4;
	y1=4;
	
	dx=(x1-x0);
	dy=(y1-y0);
	
	//determinar que punto usar para comenzar a graficar
	if(dy<0){
		dy=-dy;
		py=-1;
	}
	else {
		py=1;
	}
	if(dx<0){
		dx=-dx;
		px=-1;
	}
	else {
		px=1;
	}
	
	x=x0;
	y=y0;
	
	glVertex2f(x0,y0);
	
	//se cicla hasta llegar al extremo de la linea
	
	if (dx>dy){
		p=2*dy-dx;
		N=2*dy;
		NE=2*(dy-dx);
		
		while (x!=x1){
			x=x+px;
			if(p<0){
				p=p+N;
			}
			else{
				y=y+py;
				p=p+NE;
			}
			glVertex2f(x,y);
			glVertex2f(x,y);
		}
	}
	else {
		p=2*dx-dy;
		N=2*dx;
		NE=2*(dx-dy);
		
		while (y!=y1){
			y=y+py;
			if(p<0){
				p=p+N;
			}
			else{
				x=x+px;
				p=p+NE;
			}
			glVertex2f(x,y);
			glVertex2f(x,y);
		
		}
	}
		
			
	

	glEnd();
	
    glFlush ();

}

void display()
{
    //  Borrar pantalla y Z-buffer
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 
    // Resetear transformaciones
    glLoadIdentity();
    glOrtho(-5.0, 5.0, -5.0, 5.0, -1.0, 1.0);
    //Llamado en el display
    Bresenham(0,0);
    glEnd();
 
    glFlush();
    glutSwapBuffers();
 
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
    glutCreateWindow("Algoritmo De Bresenham");
    
    // Habilitar la prueba de profundidad de Z-buffer
    glEnable(GL_DEPTH_TEST);
 
    // Funciones de retrollamada
    glutDisplayFunc(display);
    //glutKeyboardFunc(keyboard);
    //glutSpecialFunc(specialKeys);
 
    // Pasar el control de eventos a GLUT
    glutMainLoop();
 
    // Regresar al sistema operativo
    return 0;
 
}

