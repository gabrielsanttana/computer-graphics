#include <GL/glut.h>
#include <stdlib.h>

void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);

int main(int argc, char** argv){
  glutInit(&argc, argv); //initializes GLUT 
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //specifies the color set and buffers
  glutInitWindowSize(256, 256); //specifies the windows dimensions
  glutInitWindowPosition(100, 100); //specifies where the window should open in the screen
  glutCreateWindow ("Drawing a line"); //creates the window
  init();
  glutDisplayFunc(display); //function that will be repainted by GLUT
  glutKeyboardFunc(keyboard); //keyboard function
  glutMainLoop(); //show all created windows
                             
  return 0;
}

void init(void){
  glClearColor(0.3, 1.0, 1.0, 0.3); //defines the background color
  glOrtho (0, 256, 0, 256, -1 ,1); //set orthogonal mode
}

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT); //clears the window
  glColor3f (0.0, 0.0, 0.0); //color of the line
  glLineWidth(4.0); //width of the line
  glBegin(GL_LINES);
  glVertex2i(40,200); //coordenates of the line inital point
  glVertex2i(200,10); //coordenates of the line end point
  glEnd();
  glFlush();
}

void keyboard(unsigned char key, int x, int y) {
  switch (key) {
    case 27:
    exit(0);
    break;
  }
}
