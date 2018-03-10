#include <GL/gl.h>
#include <GL/glut.h>
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5);
double xRot=0;
glRotatef( xRot, 2.0f, 0.0f, 0.0f); 
    glBegin(GL_QUAD_STRIP);
//primer quad
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-0.5f,0.0f,0.0f);
    glVertex3f(-0.5f,0.5f,0.0f);
    glVertex3f(0.0f,-0.5f,0.0f);
    glVertex3f(0.0f,0.5f,0.0f);
    //segundo quad
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.7f,0.5f,0.0f);
    glVertex3f(0.8f,0.5f,0.0f);
    //tercer quad 
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.8f,0.5f,0.0f);
    glVertex3f(0.0f,-0.5f,0.0f);
    glVertex3f(0.8f,-0.2f,0.0f);

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
