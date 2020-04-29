#include <gl/glut.h>
#include <gl/GLU.h>
#include <gl/GL.h>

void MyDisplayCall(void) { // 디스플레이 콜백함수
	glClear(GL_COLOR_BUFFER_BIT); // GL상태변수 설정
	glViewport(200, 150, 100, 100); // 뷰포트 위치
	glColor3f(1.0, 1.0, 1.0);
	
	glutWireTeapot(0.5); // 주전자 표시

	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);  // GLUT라이브러리 초기화 및 윈도우 운영체제 연결
	glutInitDisplayMode(GLUT_RGB); // RGB모드 사용
	glutInitWindowSize(400, 300); // 윈도우 초기 크기
	glutInitWindowPosition(200, 367); // 윈도우 세로크기 고려했을때 0, 467 에서 생성된 윈도우의 좌하단이 딱 컴퓨터의 좌하단에 위치하게 됨 거기에 100만큼 올림 즉 367

	glutCreateWindow("Draw_Wire_Teapot");

	glClearColor(0.0, 0.0, 0.0, 1.0); // GL 상태변수 초기화
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glutDisplayFunc(MyDisplayCall); // GLUT 콜백함수 등록
	glutMainLoop();

	return 0;
}