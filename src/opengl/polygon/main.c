#include <stdio.h>
#include <GL/glut.h>
#include <stdlib.h>

#define WIDTH 1000
#define HEIGHT 1000

void init(void);
void display(void);
void onKeyboardPress(unsigned char key, int x, int y);
void onMouseUp(int button, int state, int x, int y);
void drawMesh();
void drawMeshTriangles(int x, int y, int meshSize);
void drawHouse();
void drawHouseCeil();
void drawHouseLateral();
void drawHouseInferiorFront();
void drawHouseSuperiorFront();
void drawHouseDoor();
void drawHouseWindow();

int GL_MODE = GL_LINE;

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WIDTH - 200, HEIGHT - 200);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Casinha");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(onKeyboardPress);
	glutMouseFunc(onMouseUp);
	glutMainLoop();

	return 0;
}

void init(void) {
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glOrtho(0, WIDTH, 0, HEIGHT, -1 ,1);
} 

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f (0.0, 0.0, 0.0);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  drawMesh();
  drawHouse();
}

void drawMesh(void) {  
	glLineWidth(1.0);
	int meshSize = 50;
	int XAxisCount;
	int YAxisCount;
	
	for(XAxisCount = 0; XAxisCount < WIDTH; XAxisCount += meshSize){
		for(YAxisCount = 0; YAxisCount < HEIGHT; YAxisCount += meshSize){
			drawMeshTriangles(XAxisCount,YAxisCount,meshSize);
		}	
	}
}

void drawMeshTriangles(int x, int y, int meshSize) {
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2i(x, y);  
  glVertex2i(x, y + meshSize);  
  glVertex2i(x + meshSize, y + meshSize); 
  glVertex2i(x + meshSize, y); 
  glVertex2i(x, y);
	glEnd();
	glFlush();
}

void drawHouseCeil() {
  glColor3f (0.0, 0.0, 1.0); 
	glBegin(GL_POLYGON);
	glVertex2i(450, 300);glVertex2i(300,  450);glVertex2i(600, 450 );glVertex2i(750, 300);glVertex2i(450, 300);
	glEnd();
}

void drawHouseLateral() {
  glColor3f (0.0, 1.0, 0.0); 
	glBegin(GL_POLYGON);
	glVertex2i(450,  50);
  glVertex2i(450, 300);
  glVertex2i(750, 300);
  glVertex2i(750, 50);
  glVertex2i(450, 50);
	glEnd();
}

void drawHouseInferiorFront() {
  glColor3f (1.0, 0.0, 0.0); 
	glBegin(GL_POLYGON);
	glVertex2i(150,50);
  glVertex2i(150,300);
  glVertex2i(450,300);
  glVertex2i(450,50);
  glVertex2i(150,50);
	glEnd();
}

void drawHouseSuperiorFront() {
  glColor3f(1.0, 0.0, 0.0); 
	glBegin(GL_POLYGON);
	glVertex2i(150, 300);
  glVertex2i(300, 450);
  glVertex2i(450, 300);
  glVertex2i(150, 300);
	glEnd();
}

void drawHouseDoor() {
  glColor3f(1.0, 1.0, 0.0); 
	glBegin(GL_POLYGON);
	glVertex2i(250,50);
  glVertex2i(250,200);
  glVertex2i(350,200);
  glVertex2i(350,50);
  glVertex2i(250,50);
	glEnd();
}

void drawHouseWindow() {
  glBegin(GL_POLYGON);
	glVertex2i(550, 150);
  glVertex2i(550, 250);
  glVertex2i(650, 250); 
  glVertex2i(650, 150);
  glVertex2i(550, 150);
	glEnd();
}

void drawHouse() {
	glLineWidth(4.0);           
	glPolygonMode(GL_FRONT_AND_BACK, GL_MODE);

  drawHouseCeil();
  drawHouseLateral();
  drawHouseInferiorFront();
  drawHouseSuperiorFront();
  drawHouseDoor();
  drawHouseWindow();

	glFlush();	
}

void onMouseUp(int button, int state, int x, int y) {
	if(GLUT_UP == state) {
    if(GL_MODE == GL_LINE) {
			GL_MODE = GL_FILL;
		} else {
			GL_MODE = GL_LINE;
		}
  }
}

void onKeyboardPress(unsigned char key, int x, int y) {
  switch (key) {
    case 27:
      exit(0);
      break;
  }
}
