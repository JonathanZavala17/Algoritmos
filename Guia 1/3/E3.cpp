#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(2);
    glColor3f(0.0f, 0.0f, 1.0f);
    GLfloat angulo;
    double i;
    double P;
    double u = i;
    //double k = i/3;
    
    glBegin(GL_POINTS);
    for(i=-3.0; i<=1.0; i+=0.04167)
    {
		double u = i;
                P= ((3*i)+7);
                
                glVertex3f(u,P,0.0f);
		}
glEnd();

glPointSize(5);
glBegin(GL_POINTS);
glColor3f(1.0f, 0.0f, 0.0f);
    for(i=-3.0; i<=1.0; i+=1/3.0)
    {
		double u = i;
                P= ((3*i)+7);
                
                glVertex3f(u,P,0.0f);
		}
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 1.0f, 1.0f);
glVertex3f(-3.0f,0.0f,0.0f);
glVertex3f(3.0f,0.0f,0.0f);
glVertex3f(0.0f,10.5f,0.0f);
glVertex3f(0.0f,-2.0f,0.0f);


    glEnd();
    glFlush ();

}
void init (void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-4.0, 4.0, -3.0, 11.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (800, 600);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Funcion 2");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
