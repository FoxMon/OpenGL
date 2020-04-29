#include <gl/glut.h>
#include <gl/GLU.h>
#include <gl/GL.h>

void MyDisplayCall(void) { // ���÷��� �ݹ��Լ�
	glClear(GL_COLOR_BUFFER_BIT); // GL���º��� ����
	glViewport(200, 150, 100, 100); // ����Ʈ ��ġ
	glColor3f(1.0, 1.0, 1.0);
	
	glutWireTeapot(0.5); // ������ ǥ��

	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);  // GLUT���̺귯�� �ʱ�ȭ �� ������ �ü�� ����
	glutInitDisplayMode(GLUT_RGB); // RGB��� ���
	glutInitWindowSize(400, 300); // ������ �ʱ� ũ��
	glutInitWindowPosition(200, 367); // ������ ����ũ�� ��������� 0, 467 ���� ������ �������� ���ϴ��� �� ��ǻ���� ���ϴܿ� ��ġ�ϰ� �� �ű⿡ 100��ŭ �ø� �� 367

	glutCreateWindow("Draw_Wire_Teapot");

	glClearColor(0.0, 0.0, 0.0, 1.0); // GL ���º��� �ʱ�ȭ
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glutDisplayFunc(MyDisplayCall); // GLUT �ݹ��Լ� ���
	glutMainLoop();

	return 0;
}