#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(2);
    glColor3f(1.0f, 1.0f, 1.0f);
    GLfloat angulo;
    double i;
    double P;
    double u = i;
    //double g= 1/3;
    glBegin(GL_POINTS);
    for (i=-2.5; i<1.5; i+=0.1)
    {
		
		double u = i;
                P= ((2*i*i)+(3*i)-2);
                
                glVertex3f(u,P,0.0f);
		}
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 1.0f, 1.0f);
glVertex3f(-2.5f,0.0f,0.0f);
glVertex3f(1.5f,0.0f,0.0f);
glVertex3f(0.0f,1.5f,0.0f);
glVertex3f(0.0f,-3.5f,0.0f);
    glEnd();

glPointSize(5);
glBegin(GL_POINTS);
glColor3f(1.0f, 0.0f, 0.0f);
glVertex3f(-2.0f,0.0f,0.0f);
glVertex3f(0.5f,0.0f,0.0f);
glVertex3f(0.0f,-2.0f,0.0f);
    glEnd();
    glFlush ();

}
void init (void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-3.0, 2.0, -4.0, 1.7, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (800, 600);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Funcion 1");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
