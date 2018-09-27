#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <gl/glut.h>
void init(void)
{
    glClearColor(1.0,1.0,1.0,1.0); // Ϊɫ�ʻ�����ָ�����������ֵ
	gluOrtho2D(0.0,20.0,0.0,20.0);    // �ü���Ұ ����Ϊ(0,0) ~ (20,20)���ڹ۲�
}

void display(void)
{

    int x0 = 1,y0 = 3,x1 = 9,y1 = 18;
	int dx = x1 - x0;  // xƫ����
	int dy = y1 - y0;  // yƫ����
    int dx2 = dx * 2;
    int dy2 = dy * 2;
    int e = dy2 - dx;    // e = -0.5*2*dx
    int x = x0; // �������
    int y = y0;
	glClear(GL_COLOR_BUFFER_BIT);   // ���������
	glColor3f(1.0,0.0,0.0); // ������ɫ
	glBegin(GL_LINES);  // ��ʼ����һ��㻭ͼ��ÿ��������Ϊһ���������߶�
        glVertex2i(x,y);    // ָ�������ά����int��
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
	glEnd();    //����
	glFlush();  // �����޵�ʱ����ǿ��OpenGL��ִ��

}

int main(int argc,char ** argv)
{
    glutInit(&argc,argv); // ��ʼ��GLUT��
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); // ����ͼ����ʾģʽ
    // ��ʼ�����ڴ�С��λ��
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(50,100);
    glutCreateWindow("Bresenham Draw"); //����һ������Ĵ���
    init();    // ��ʼ����ɫ��Ϣ
    glutDisplayFunc(display);// Ϊ��ǰ�������ûص�����
    // glut��������¼�ѭ��
    glutMainLoop();
    return 0;
}
