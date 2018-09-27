#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <gl/glut.h>
void init(void)
{
    glClearColor(1.0,1.0,1.0,1.0); // 为色彩缓冲区指定用于清除的值
	gluOrtho2D(-20.0,20.0,-20.0,20.0);    // 裁剪视野 设置为(-20,-20) ~ (20,20)便于观察
}
/*
    画点
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
    同时画4个对称点
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
    glutInit(&argc,argv); // 初始化GLUT库
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); // 设置图形显示模式
    // 初始化窗口大小和位置
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(50,50);
    glutCreateWindow("MidCircle Draw"); //产生一个顶层的窗口
    init();    // 初始化颜色信息
    glutDisplayFunc(display);// 为当前窗口设置回调函数
    // glut程序进入事件循环
    glutMainLoop();
    return 0;
}
