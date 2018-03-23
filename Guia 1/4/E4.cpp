#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(2);
    glBegin(GL_POINTS);
    double inicio = -3*M_PI;
    double final = 5*M_PI;
    double i;
    double k;
    double u=0;
    double P=0;
	
	glColor3f(1.0f,1.0f,1.0f);
//Algoritmo de furrier
    for(i=inicio; i<=final; i+=0.0015)    
    {	
		u=i;
		k=2;
		P=k+((4*k)/M_PI)*((sin(u))+((1/3.0)*(sin(3*(u))))+((1/5.0)*(sin(5*(u))))+((1/7.0)*(sin(7*(u))))+((1/9.0)*(sin(9*(u))))+((1/11.0)*(sin(11*(u))))+((1/13.0)*(sin(13*(u))))+((1/15.0)*(sin(15*(u))))+((1/17.0)*(sin(17*(u))))+((1/19.0)*(sin(19*(u))))+((1/21.0)*(sin(21*(u))))+((1/23.0)*(sin(23*(u))))+((1/25.0)*(sin(25*(u))))+((1/27.0)*(sin(27*(u))))+((1/29.0)*(sin(29*(u))))+((1/31.0)*(sin(31*(u))))+((1/33.0)*(sin(33*(u))))+((1/35.0)*(sin(35*(u))))+((1/37.0)*(sin(37*(u))))+((1/39.0)*(sin(39*(u))))+((1/41.0)*(sin(41*(u))))+((1/43.0)*(sin(43*(u))))+((1/45.0)*(sin(45*(u))))+((1/47.0)*(sin(47*(u))))+((1/49.0)*(sin(49*(u))))+((1/51.0)*(sin(51*(u))))+((1/53.0)*(sin(53*(u))))+((1/57.0)*(sin(57*(u))))+((1/59.0)*(sin(59*(u))))+((1/61.0)*(sin(61*(u))))+((1/63.0)*(sin(63*(u))))+((1/65.0)*(sin(65*(u))))+((1/67.0)*(sin(67*(u))))+((1/69.0)*(sin(69*(u))))+((1/71.0)*(sin(71*(u))))+((1/73.0)*(sin(73*(u))))+((1/75.0)*(sin(75*(u))))+((1/77.0)*(sin(77*(u))))+((1/79.0)*(sin(79*(u))))+((1/81.0)*(sin(81*(u))))+((1/83.0)*(sin(83*(u))))+((1/85.0)*(sin(85*(u))))+((1/87.0)*(sin(87*(u))))+((1/89.0)*(sin(89*(u))))+((1/91.0)*(sin(91*(u))))+((1/93.0)*(sin(93*(u))))+((1/95.0)*(sin(95*(u))))+((1/97.0)*(sin(97*(u))))+((1/99.0)*(sin(99*(u)))));
		
		glVertex3f(u,P,0.0f);	
		
		}
	
	
	
	glEnd();
glBegin(GL_LINES);
glColor3f(0.0f, 1.0f, 1.0f);
glVertex3f(-10.0f,0.0f,0.0f);
glVertex3f(16.0f,0.0f,0.0f);
glVertex3f(0.0f,8.0f,0.0f);
glVertex3f(0.0f,-2.0f,0.0f);


    glEnd();
	
    glFlush ();

}
void init (void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-12.0, 18.0, -3.0, 9.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (800, 600);
    glutInitWindowPosition (400, 100);
    glutCreateWindow ("Furrier");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
