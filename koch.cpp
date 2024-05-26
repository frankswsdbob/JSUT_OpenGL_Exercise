#include <GL/glut.h>
#include <cmath>
#include <GL/glut.h>
#define M_PI 3.14

void koch(int x1, int y1, int x2, int y2, int it)
{
    if (it == 0)
    {
        glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glEnd();
    }
    else
    {
        int deltaX = x2 - x1;
        int deltaY = y2 - y1;

        int x3 = x1 + deltaX / 3;
        int y3 = y1 + deltaY / 3;

        int x4 = x3 + (int)(cos(M_PI / 3) * deltaX / 3 - sin(M_PI / 3) * deltaY / 3);
        int y4 = y3 + (int)(sin(M_PI / 3) * deltaX / 3 + cos(M_PI / 3) * deltaY / 3);

        int x5 = x1 + 2 * deltaX / 3;
        int y5 = y1 + 2 * deltaY / 3;

        koch(x1, y1, x3, y3, it - 1);
        koch(x3, y3, x4, y4, it - 1);
        koch(x4, y4, x5, y5, it - 1);
        koch(x5, y5, x2, y2, it - 1);
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0); // 设置颜色
    glLineWidth(1.0); // 设置线宽
    glPushMatrix();
    koch(100, 200, 400, 200, 5); // 绘制Koch曲线
    glPopMatrix();
    glFlush();
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0); // 设置清屏颜色
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0); // 设置视图窗口大小
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Koch Curve");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
