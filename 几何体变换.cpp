#include <GL/glut.h>

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-5.0, 5.0, -5.0, 5.0);
	//������ʾ�ķ�Χ��X:-5.0~5.0, Y:-5.0~5.0
	glMatrixMode(GL_MODELVIEW);
}


void drawSquare1(void)
{
	glBegin(GL_POLYGON);      //����ָ����Ҫ����ʱ�뷽��	��
	glVertex2f(-1.5f, -1.0f);
	glVertex2f(0.2f, -1.0f);
	glVertex2f(0.7f, 1.0f);
	glVertex2f(-1.0f, 1.0f);
	glEnd();
}
void drawSquare2(void)    
{
	glBegin(GL_POLYGON);      //����ָ����Ҫ����ʱ�뷽��	��
	glVertex2f(-0.5f, -1.0f);
	glVertex2f(1.2f, -1.0f);
	glVertex2f(0.7f, 1.0f);
	glVertex2f(-1.0f, 1.0f);
	glEnd();
}



void drawSquare3(void)
{
	glBegin(GL_POLYGON);      //����ָ����Ҫ����ʱ�뷽��	��
	glVertex2f(-1.0f, -1.0f);
	glVertex2f(0.7f, -0.7f);
	glVertex2f(1.0f, 1.0f);
	glVertex2f(-0.7f, 0.7f);
	glEnd();
}

void myDraw(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	

	glPushMatrix();

	glTranslatef(-1, -1.0, 0.0);
	glPushMatrix();
	glRotatef(0.0, 0.0, 0.0, 1.0);
	glColor3f(0.0, 1.0, 0.0);
	drawSquare1();                 //������
	glPopMatrix();
	

	glTranslatef(2, 0.0, 0.0);

	glPushMatrix();
	glRotatef(0.0, 0.0, 0.0, 1.0);
	glColor3f(0.0, 0.0, 1.0);
	drawSquare2();                 //������
	glPopMatrix();

	glTranslatef(-1.15, 2.5, 0.0);
	glPushMatrix();
	glRotatef(45.0, 0.0, 0.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	drawSquare3();                 //������
	glPopMatrix();

	glPopMatrix();

	
	glFlush();
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(600, 600);
	glutCreateWindow("���α任ʾ��");

	init();
	glutDisplayFunc(myDraw);
	glutMainLoop();
}
