#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
//Hola k ace 
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(2);
    glColor3f(1.0f, 1.0f, 1.0f);
    GLfloat angulo;
    int i;
    
    glBegin(GL_LINES);
    for (i=0; i<360; i+=1)
    {
		angulo = i*M_PI/180.0f; //grados a radianes
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(cos(angulo),sin(angulo),0.0f);
		}
    glEnd();
    glFlush ();

}
void init (void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (250, 250);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Ejemplo Puntos");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
