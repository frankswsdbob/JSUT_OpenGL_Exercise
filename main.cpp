
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
// 此代码模块中包含的函数的前向声明:
float theta = 0.0;
float theta_line = 0.0;
void Keyboard(unsigned char key, int x, int y);
void Display(void);
void Reshape(int w, int h);
void mytime(int t);
void init();
int main(int argc, char* argv[])
{
	glutInit(&argc, argv); //初始化GTD工座
	glutInitWindowSize(700, 700);//设置显示窗口大小
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // 设置显示模式 (注意双缓存)
	glutCreateWindow("A Rotating Square"); // 创建显示窗口
	init();
	glutDisplayFunc(Display); // 注册显示回调函数
	glutReshapeFunc(Reshape); //注册窗口改变回调函数
	glutTimerFunc(1000, mytime, 10); //1000毫秒后调用时间函数mytime
	glutMainLoop(); //进入事件处理循环
	return 0;
}
void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glLineWidth(2.0);
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < n; i++) { //绘制正六边形
		glVertex2f(R * cos(theta + i * 2 * PI / n), R * sin(theta + i * 2 * PI / n));
	}
	glEnd();
	//xc,yc为时针中心点坐标
	//xs,ys为秒针终止点坐标
	//xm,ym为分针终止点坐标
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
	glutSwapBuffers();//双缓存的刷新模式
}
void mytime(int t)
{
	GetLocalTime(&timeNow);
	hh = timeNow.wHour;
	mm = timeNow.wMinute;
	ss = timeNow.wSecond;
	glutPostRedisplay(); //重画，相当于重新调用Display()，改变后的变量得以传给绘制函数
	glutTimerFunc(1000, mytime, 10);
}
void Reshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION); //投影矩阵模式
	glLoadIdentity(); //矩阵堆栈清空
	gluOrtho2D(-1.5 * R * w / h, 1.5 * R * w / h, -1.5 * R, 1.5 * R);//设置裁剪窗口大小
	glViewport(0, 0, w, h);// 设置视区大小
	glMatrixMode(GL_MODELVIEW); //模型矩阵模式
}
void init()
{
	GetLocalTime(&timeNow);// 获取系统时间
	hh = timeNow.wHour;//获取小时时间
	mm = timeNow.wMinute;//获取分钟时间
	ss = timeNow.wSecond;//获取秒时间
}
