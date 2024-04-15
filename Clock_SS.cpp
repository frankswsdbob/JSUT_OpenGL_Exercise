
#include <stdio.h>
#include <gl/glut.h>
#include <math.h>
#include <time.h>
#define MAX_LOADSTRING 100
#define PI 3.14159
SYSTEMTIME timeNow;
float hh, mm, ss;
int n = 6, R = 10;
int k = 0;
// �˴���ģ���а����ĺ�����ǰ������:
float theta = 0.0;
float theta_line = 0.0;
void Keyboard(unsigned char key, int x, int y);
void Display(void);
void Reshape(int w, int h);
void mytime(int t);
void init();
int main(int argc, char* argv[])
{
	glutInit(&argc, argv); //��ʼ��GTD����
	glutInitWindowSize(700, 700);//������ʾ���ڴ�С
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // ������ʾģʽ (ע��˫����)
	glutCreateWindow("A Rotating Square"); // ������ʾ����
	init();
	glutDisplayFunc(Display); // ע����ʾ�ص�����
	glutReshapeFunc(Reshape); //ע�ᴰ�ڸı�ص�����
	glutTimerFunc(1000, mytime, 10); //1000��������ʱ�亯��mytime
	glutMainLoop(); //�����¼�����ѭ��
	return 0;
}
void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glLineWidth(2.0);
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < n; i++) { //������������
		glVertex2f(R * cos(theta + i * 2 * PI / n), R * sin(theta + i * 2 * PI / n));
	}
	glEnd();
	//xc,ycΪʱ�����ĵ�����
	//xs,ysΪ������ֹ������
	//xm,ymΪ������ֹ������
	float xs, ys, xm, ym, xh, yh;
	float xc = 0, yc = 0;
	//Calculate
	xs = xc + R * cos(PI / 2.0 - ss / 60 * 2 * PI);
	ys = yc + R * sin(PI / 2.0 - ss / 60 * 2 * PI);
	xm = xc + R * cos(PI / 2.0 - (mm + ss / 60.0) / 60.0 * 2.0 * PI);
	ym = yc + R * sin(PI / 2.0 - (mm + ss / 60.0) / 60.0 * 2.0 * PI);
	xh = xc + (R - 5) * cos(PI / 2.0 - (hh + (mm + ss / 60.0) / 60.0) / 12.0 * 2.0 * PI);
	yh = yc + (R - 5) * sin(PI / 2.0 - (hh + (mm + ss / 60.0) / 60.0) / 12.0 * 2.0 * PI);
	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(xc, yc);
	glVertex2f(xs, ys);
	glEnd();
	glColor3f(1, 1, 0);
	glBegin(GL_LINES);
	glVertex2f(xc, yc);
	glVertex2f(xm, ym);
	glEnd();
	glColor3f(0, 1, 1);
	glBegin(GL_LINES);
	glVertex2f(xc, yc);
	glVertex2f(xh, yh);
	glEnd();
	glutSwapBuffers();//˫�����ˢ��ģʽ
}
void mytime(int t)
{
	GetLocalTime(&timeNow);
	hh = timeNow.wHour;
	mm = timeNow.wMinute;
	ss = timeNow.wSecond;
	glutPostRedisplay(); //�ػ����൱�����µ���Display()���ı��ı������Դ������ƺ���
	glutTimerFunc(1000, mytime, 10);
}
void Reshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION); //ͶӰ����ģʽ
	glLoadIdentity(); //�����ջ���
	gluOrtho2D(-1.5 * R * w / h, 1.5 * R * w / h, -1.5 * R, 1.5 * R);//���òü����ڴ�С
	glViewport(0, 0, w, h);// ����������С
	glMatrixMode(GL_MODELVIEW); //ģ�;���ģʽ
}
void init()
{
	GetLocalTime(&timeNow);// ��ȡϵͳʱ��
	hh = timeNow.wHour;//��ȡСʱʱ��
	mm = timeNow.wMinute;//��ȡ����ʱ��
	ss = timeNow.wSecond;//��ȡ��ʱ��
}
