#include <gl/glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>

GLboolean IsSphere = true;
GLboolean IsSmall = true;
GLboolean IsRender = true; // false 일 때 solid, true 일 때 wire

void MyDisplay(void) { // Display 콜백함수
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.0, 0.5);
	
	if ((IsSphere) && (IsSmall) && (IsRender)) { // 작은 wire 구체
		glutWireSphere(0.2, 15, 15);
	}
	else if ((IsSphere) && (!IsSmall) && (IsRender)) { // 큰 wire 구체
		glutWireSphere(0.4, 15, 15);
	}
	else if ((IsSphere) && (IsSmall) && (!IsRender)) { // 작은 solid 구체
		glutSolidSphere(0.2, 15, 15);
	}
	else if ((IsSphere) && (!IsSmall) && (!IsRender)) { // 큰 solid 구체
		glutSolidSphere(0.4, 15, 15);
	}
	else if ((!IsSphere) && (IsSmall) && (IsRender)) { // 작은 wire Torus
		glutWireTorus(0.1, 0.3, 40, 20);
	}
	else if ((!IsSphere) && (!IsSmall) && (IsRender)) { // 큰 wire Torus
		glutWireTorus(0.2, 0.5, 40, 20);
	}
	else if ((!IsSphere) && (IsSmall) && (!IsRender)) { // 작은 solid torus
		glutSolidTorus(0.1, 0.3, 40, 20);
	}
	else { // 큰 solid torus
		glutSolidTorus(0.2, 0.5, 40, 20);
	}

	glFlush(); // 버퍼 모두 내보냄
}

void MyMainMenu(int entryID) { // 메인 메뉴 콜백함수
	if (entryID == 1) {
		IsSphere = true;
	}
	else if (entryID == 2) {
		IsSphere = false;
	}
	else if (entryID == 3) { // 전달된 entry ID가 3이면 종료
		exit(0);
	}

	glutPostRedisplay();
}

void MySubMenu(int entryID) { // 서브 메뉴 콜백 함수 ( 크기 )
	if (entryID == 1) {
		IsSmall = true;
	}
	else if (entryID == 2) {
		IsSmall = false;
	}

	glutPostRedisplay();
}

void MyRenSubMenu(int entryID) { // 서브 메뉴 콜백 함수 ( 렌더링 모드 )
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

	glutInitDisplayMode(GLUT_RGB); // RGB 모드 
	glutInitWindowSize(300, 300); // 윈도우 사이즈
	glutInitWindowPosition(0, 0); // 좌상단 초기 윈도우 생성

	glutCreateWindow("Subject03"); // 윈도우 Title

	glClearColor(1.0, 1.0, 1.0, 1.0); // 배경색 white
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	GLint MySubMenuID = glutCreateMenu(MySubMenu); // 크기에 관한 SubMenu ID
	glutAddMenuEntry("Small One", 1);
	glutAddMenuEntry("Big One", 2);

	GLint MyRenSubMenuID = glutCreateMenu(MyRenSubMenu); // 렌더링에 관한 SubMenu ID
	glutAddMenuEntry("Wire Rendering", 1);
	glutAddMenuEntry("Solid Rendering", 2);

	GLint MyMainMenuID = glutCreateMenu(MyMainMenu); // 메인메뉴 등록
	glutAddMenuEntry("Draw Sphere", 1);
	glutAddMenuEntry("Draw Torus", 2);

	glutAddSubMenu("Change Size", MySubMenuID); // 서브메뉴 등록
	glutAddSubMenu("Rendering Mode", MyRenSubMenuID); // 서브메뉴 등록

	glutAddMenuEntry("Exit", 3); // 3 전달 , 종료시점

	glutAttachMenu(GLUT_RIGHT_BUTTON); // 우클릭 시 Cacade Menu 열림

	glutDisplayFunc(MyDisplay); // Display CallBack 함수 등록

	glutMainLoop(); // 이벤트 루프

	return 0;
}