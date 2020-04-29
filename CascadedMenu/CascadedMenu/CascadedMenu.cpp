#include <gl/glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>

GLboolean IsSphere = true;
GLboolean IsSmall = true;
GLboolean IsRender = true; // false �� �� solid, true �� �� wire

void MyDisplay(void) { // Display �ݹ��Լ�
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.0, 0.5);
	
	if ((IsSphere) && (IsSmall) && (IsRender)) { // ���� wire ��ü
		glutWireSphere(0.2, 15, 15);
	}
	else if ((IsSphere) && (!IsSmall) && (IsRender)) { // ū wire ��ü
		glutWireSphere(0.4, 15, 15);
	}
	else if ((IsSphere) && (IsSmall) && (!IsRender)) { // ���� solid ��ü
		glutSolidSphere(0.2, 15, 15);
	}
	else if ((IsSphere) && (!IsSmall) && (!IsRender)) { // ū solid ��ü
		glutSolidSphere(0.4, 15, 15);
	}
	else if ((!IsSphere) && (IsSmall) && (IsRender)) { // ���� wire Torus
		glutWireTorus(0.1, 0.3, 40, 20);
	}
	else if ((!IsSphere) && (!IsSmall) && (IsRender)) { // ū wire Torus
		glutWireTorus(0.2, 0.5, 40, 20);
	}
	else if ((!IsSphere) && (IsSmall) && (!IsRender)) { // ���� solid torus
		glutSolidTorus(0.1, 0.3, 40, 20);
	}
	else { // ū solid torus
		glutSolidTorus(0.2, 0.5, 40, 20);
	}

	glFlush(); // ���� ��� ������
}

void MyMainMenu(int entryID) { // ���� �޴� �ݹ��Լ�
	if (entryID == 1) {
		IsSphere = true;
	}
	else if (entryID == 2) {
		IsSphere = false;
	}
	else if (entryID == 3) { // ���޵� entry ID�� 3�̸� ����
		exit(0);
	}

	glutPostRedisplay();
}

void MySubMenu(int entryID) { // ���� �޴� �ݹ� �Լ� ( ũ�� )
	if (entryID == 1) {
		IsSmall = true;
	}
	else if (entryID == 2) {
		IsSmall = false;
	}

	glutPostRedisplay();
}

void MyRenSubMenu(int entryID) { // ���� �޴� �ݹ� �Լ� ( ������ ��� )
	if (entryID == 1) {
		IsRender = true;
	}
	else if (entryID == 2) {
		IsRender= false;
	}

	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB); // RGB ��� 
	glutInitWindowSize(300, 300); // ������ ������
	glutInitWindowPosition(0, 0); // �»�� �ʱ� ������ ����

	glutCreateWindow("Subject03"); // ������ Title

	glClearColor(1.0, 1.0, 1.0, 1.0); // ���� white
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	GLint MySubMenuID = glutCreateMenu(MySubMenu); // ũ�⿡ ���� SubMenu ID
	glutAddMenuEntry("Small One", 1);
	glutAddMenuEntry("Big One", 2);

	GLint MyRenSubMenuID = glutCreateMenu(MyRenSubMenu); // �������� ���� SubMenu ID
	glutAddMenuEntry("Wire Rendering", 1);
	glutAddMenuEntry("Solid Rendering", 2);

	GLint MyMainMenuID = glutCreateMenu(MyMainMenu); // ���θ޴� ���
	glutAddMenuEntry("Draw Sphere", 1);
	glutAddMenuEntry("Draw Torus", 2);

	glutAddSubMenu("Change Size", MySubMenuID); // ����޴� ���
	glutAddSubMenu("Rendering Mode", MyRenSubMenuID); // ����޴� ���

	glutAddMenuEntry("Exit", 3); // 3 ���� , �������

	glutAttachMenu(GLUT_RIGHT_BUTTON); // ��Ŭ�� �� Cacade Menu ����

	glutDisplayFunc(MyDisplay); // Display CallBack �Լ� ���

	glutMainLoop(); // �̺�Ʈ ����

	return 0;
}