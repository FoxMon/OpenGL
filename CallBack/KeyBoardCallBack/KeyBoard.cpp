#include <gl/glut.h>
#include <gl/GLU.h>
#include <gl/GL.h>

void MyKeyboard(unsigned char keyPressed, int x, int y) { // Key Event Callback Function
	switch(keyPressed) {
		case 'Q':
			exit(0);
			break;
		case 'q':
			exit(0);
			break;
		case 27:
			exit(0);
			break;
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Drawing Practice");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glutKeyboardFunc(MyKeyboard);
	glutMainLoop();
	return 0;
}