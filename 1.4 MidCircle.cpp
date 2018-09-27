#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <gl/glut.h>
void init(void)
{
    glClearColor(1.0,1.0,1.0,1.0); // Ϊɫ�ʻ�����ָ�����������ֵ
	gluOrtho2D(-20.0,20.0,-20.0,20.0);    // �ü���Ұ ����Ϊ(-20,-20) ~ (20,20)���ڹ۲�
}
/*
    ����
*/
void drawPixel(int x, int y){
    glColor3f(1.0,0.0,0.0);
    glPointSize(2.0f);
	glBegin(GL_POINTS);
        glVertex2f(x,y);
    glEnd();
	glFlush();
}
/*
    ͬʱ��4���ԳƵ�
*/
void drawFour(int x0, int y0, int x, int y){
    drawPixel(x0 + x, y0 + y);
    drawPixel(x0 + y, y0 + x);
    drawPixel(x0 - x, y0 + y);
    drawPixel(x0 - y, y0 + x);
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    int x0 = 3,y0 = -2,r = 12;
    int x = 0, y = r;
    int d = 1-r; // floor(1.25-r)
    drawFour(x0, y0, x, y);
    while(x < y){
        if(d < 0){
            d = d + 2*x + 3;
        }
        else{
            d = d + 2*(x-y) + 5;
            y--;
        }
        x++;
        drawFour(x0, y0, x, y);
    }
}
int main(int argc,char ** argv)
{
    glutInit(&argc,argv); // ��ʼ��GLUT��
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); // ����ͼ����ʾģʽ
    // ��ʼ�����ڴ�С��λ��
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(50,50);
    glutCreateWindow("MidCircle Draw"); //����һ������Ĵ���
    init();    // ��ʼ����ɫ��Ϣ
    glutDisplayFunc(display);// Ϊ��ǰ�������ûص�����
    // glut��������¼�ѭ��
    glutMainLoop();
    return 0;
}
