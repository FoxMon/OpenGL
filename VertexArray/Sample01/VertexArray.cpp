#include <gl/glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>

GLfloat MyVertices[8][3] = { 
	{-0.25, -0.25, 0.25}, {-0.25, 0.25, 0.25}, {0.25, 0.25, 0.25}, 
	{0.25, -0.25, 0.25}, {-0.25, -0.25, 0.25}, {-0.25, 0.25, -0.25}, 
	{0.25, 0.25, -0.25} , {0.25, -0.25, -0.25} };	 // 육면체 정점좌표
GLfloat MyColor[8][3] = { 
	{0.2, 0.2, 0.2}, {1.0, 0.0, 0.0}, {1.0, 1.0, 0.0},
	{0.0, 0.1, 0.0}, {0.0, 0.0, 1.0}, {1.0, 0.0, 1.0}, 
	{1.0, 1.0, 1.0}, {0.0, 1.0, 1.0} }; // 정점 색
GLbyte MyVertexList[24] = { 0, 3, 2, 1, 2, 3, 7, 6, 0, 4, 7, 3, 1, 2, 6, 5, 4, 5, 6, 7, 0, 1, 5, 4 };

void MyDisplay() { // 디스플레이 이벤트 함수 정의
	glClear(GL_COLOR_BUFFER_BIT);
	glFrontFace(GL_CCW); // 반시계
	glEnable(GL_CULL_FACE);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY); // 정점 기능배열 활성화
	glColorPointer(3, GL_FLOAT, 0, MyColor); // 실제 컬러 색
	glVertexPointer(3, GL_FLOAT, 0, MyVertices);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//glRotatef(30.0, 1.0, 1.0, 1.0);
	glTranslatef(0.25f, 0.25f, .025f); // 이쪽에 위치시킴
	glTranslatef(-0.25f, -0.25f, -0.25f); // 처음 위치로 다시 돌아 가서
	glRotatef(30, 0.0f, 0.0f, 1.0f); // z축 중심 회전 시키고
	glTranslatef(0.25f, 0.25f, .025f); // 다시 원위치


	for (GLint i = 0; i < 6; i++) {
		glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, &MyVertexList[4*i]); // 실제로 육면체 그림
	}
	
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB); // RGB 색 모드
	glutInitWindowSize(300, 300); // 초기 윈도우 사이즈
	glutInitWindowPosition(0, 0); // 생성되는 윈도우 위치
	glutCreateWindow("Vertex Test");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glutDisplayFunc(MyDisplay); // 콜백함수 등록
	glutMainLoop(); // 이벤트 메인루프

	return 0;
}