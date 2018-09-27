#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <gl/glut.h>
void init(void)
{
    glClearColor(1.0,1.0,1.0,1.0); // 为色彩缓冲区指定用于清除的值
	gluOrtho2D(0.0,20.0,0.0,20.0);    // 裁剪视野 设置为(0,0) ~ (20,20)便于观察
}

void display(void)
{

    int x0 = 1,y0 = 3,x1 = 9,y1 = 18;
	int dx = x1 - x0;  // x偏移量
	int dy = y1 - y0;  // y偏移量
    int dx2 = dx * 2;
    int dy2 = dy * 2;
    int e = dy2 - dx;    // e = -0.5*2*dx
    int x = x0; // 绘制起点
    int y = y0;
	glClear(GL_COLOR_BUFFER_BIT);   // 清除缓冲区
	glColor3f(1.0,0.0,0.0); // 设置颜色
	glBegin(GL_LINES);  // 开始操作一组点画图，每个顶点作为一个独立的线段
        glVertex2i(x,y);    // 指定顶点二维坐标int型
        while(x < x1)
        {
            x++;
            e = e + dy2;
            if(e > 0){
                y++;
                e = e - dx2;    //e = e + 2*dy - 2*dx
            }
            glVertex2i(x,y);
        }
	glEnd();    //结束
	glFlush();  // 在有限的时间里强制OpenGL的执行

}

int main(int argc,char ** argv)
{
    glutInit(&argc,argv); // 初始化GLUT库
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); // 设置图形显示模式
    // 初始化窗口大小和位置
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(50,100);
    glutCreateWindow("Bresenham Draw"); //产生一个顶层的窗口
    init();    // 初始化颜色信息
    glutDisplayFunc(display);// 为当前窗口设置回调函数
    // glut程序进入事件循环
    glutMainLoop();
    return 0;
}
