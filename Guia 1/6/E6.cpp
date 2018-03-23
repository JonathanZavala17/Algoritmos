#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(2);
    
    GLfloat angulo;
    double inicio = -3*M_PI;
    double final = 3*M_PI;
    double i;
    double k;
    double u=0;
    double P=0;
glBegin(GL_POINTS);
    for (i=inicio; i<final; i+=0.01)
    {
		//angulo = i*M_PI/180.0f;
		double u = i;
                P=cos(i)/sin(i);
                glVertex3f(u,P,0.0f);
		}
glEnd(); 
glBegin(GL_LINES);
glColor3f(0.0f, 1.0f, 1.0f);
glVertex3f(-11.8f,0.0f,0.0f);
glVertex3f(11.8f,0.0f,0.0f);
glVertex3f(0.0f,9.8f,0.0f);
glVertex3f(0.0f,-9.8f,0.0f);
glEnd(); 
glFlush ();

}
void init (void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-12.0, 12.0, -10.0, 10.0, -10.0, 10.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (800, 600);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Cotangente");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
