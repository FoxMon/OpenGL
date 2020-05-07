#include <gl/glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>

GLfloat MyVertices[8][3] = { 
	{-0.25, -0.25, 0.25}, {-0.25, 0.25, 0.25}, {0.25, 0.25, 0.25}, 
	{0.25, -0.25, 0.25}, {-0.25, -0.25, 0.25}, {-0.25, 0.25, -0.25}, 
	{0.25, 0.25, -0.25} , {0.25, -0.25, -0.25} };	 // ����ü ������ǥ
GLfloat MyColor[8][3] = { 
	{0.2, 0.2, 0.2}, {1.0, 0.0, 0.0}, {1.0, 1.0, 0.0},
	{0.0, 0.1, 0.0}, {0.0, 0.0, 1.0}, {1.0, 0.0, 1.0}, 
	{1.0, 1.0, 1.0}, {0.0, 1.0, 1.0} }; // ���� ��
GLbyte MyVertexList[24] = { 0, 3, 2, 1, 2, 3, 7, 6, 0, 4, 7, 3, 1, 2, 6, 5, 4, 5, 6, 7, 0, 1, 5, 4 };

void MyDisplay() { // ���÷��� �̺�Ʈ �Լ� ����
	glClear(GL_COLOR_BUFFER_BIT);
	glFrontFace(GL_CCW); // �ݽð�
	glEnable(GL_CULL_FACE);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY); // ���� ��ɹ迭 Ȱ��ȭ
	glColorPointer(3, GL_FLOAT, 0, MyColor); // ���� �÷� ��
	glVertexPointer(3, GL_FLOAT, 0, MyVertices);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//glRotatef(30.0, 1.0, 1.0, 1.0);

	glTranslatef(0.25f, 0.25f, 0.25f); // ����ġ
	glRotatef(30, 0.0f, 0.0f, 1.0f); // z�� �߽� ȸ�� ��Ű��
	glTranslatef(-0.25f, -0.25f, -0.25f); // ����

	glTranslatef(0.25f, 0.25f,  0.25f); // �𵨺�ȯ

	for (GLint i = 0; i < 6; i++) {
		glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, &MyVertexList[4*i]); // ������ ����ü �׸�
	}
	
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB); // RGB �� ���
	glutInitWindowSize(300, 300); // �ʱ� ������ ������
	glutInitWindowPosition(0, 0); // �����Ǵ� ������ ��ġ
	glutCreateWindow("Vertex Test");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glutDisplayFunc(MyDisplay); // �ݹ��Լ� ���
	glutMainLoop(); // �̺�Ʈ ���η���

	return 0;
}