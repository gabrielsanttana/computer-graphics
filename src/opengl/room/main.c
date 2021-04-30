#include <stdlib.h>
#include <GL/glut.h>

static int rot = 0;

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (500, 500); 
  glutInitWindowPosition (100, 100);
  glutCreateWindow (argv[0]);
  init ();
  glutDisplayFunc(display); 
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  
  return 0;
}

void init(void) {
  glClearColor (0.0, 0.0, 0.0, 0.0);
}

void display(void){
  glClear (GL_COLOR_BUFFER_BIT);
  glPushMatrix();

  glRotatef ((GLfloat) rot, 0.0, 1.0, 0.0);

  /* chao */
  glPushMatrix();
  glScalef (4.0, 0.2, 6.0);
  glutWireCube (1.0);
  glPopMatrix();
   
  /* parede esquerda */
  glPushMatrix();
  glTranslatef (-1.9, 1.6, 0.0);
  glScalef (0.2, 3.0, 6.0);
  glutWireCube (1.0);
  glPopMatrix();

  /*  parede fundo */
  glPushMatrix();
  glTranslatef (0.0, 1.6, -2.9);
  glScalef (4.0, 3.0, 0.2);
  glutWireCube (1.0);
  glPopMatrix();

  /* cama */
  glPushMatrix();
  glTranslatef (-1.3, 0.6, 0.0);
  glScalef (1.0, 0.2, 2.0);
  glutWireCube (1.0);
  glPopMatrix();

  /* pe cama frente esquerdo */
  glPushMatrix();
  glTranslatef (-1.7, 0.3, 0.9);
  glScalef (0.2, 0.4, 0.2);
  glutWireCube (1.0);
  glPopMatrix();

  /* pe cama frente direito */
  glPushMatrix();
  glTranslatef (-0.9, 0.3, 0.9);
  glScalef (0.2, 0.4, 0.2);
  glutWireCube (1.0);
  glPopMatrix();

  /* pe cama cabeceira esquerdo */
  glPushMatrix();
  glTranslatef (-1.7, 0.6, -1.1);
  glScalef (0.2, 1.0, 0.2);
  glutWireCube (1.0);
  glPopMatrix();

  /* pe cama cabeceira esquerdo */
  glPushMatrix();
  glTranslatef (-0.9, 0.6, -1.1);
  glScalef (0.2, 1.0, 0.2);
  glutWireCube (1.0);
  glPopMatrix();
  
  /*Janela */
  glPushMatrix();
  glTranslatef (0, 1.5, -3);
  glScalef (2, 1.1, 0.01);
  glutWireCube (1.0);
  glPopMatrix();
  
  /*Grade vertical da janela */
  glPushMatrix();
  glTranslatef (0, 1.5, -3);
  glScalef (0.15, 1.1, 0.01);
  glutWireCube (1.0);
  glPopMatrix();
  
  /*Armario*/
  glPushMatrix();
  glTranslatef (1.5, 1.2, 1.75);
  glScalef (1.0, 2.5, 2.5);
  glutWireCube (1.0);
  glPopMatrix();

  glPopMatrix();
  glutSwapBuffers();
}

void reshape(int w, int h) {
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef (0, -3, -10.0);
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
    case 'r':
      rot = (rot + 5) % 360;
      glutPostRedisplay();
      break;
    case 'R':
      rot = (rot - 5) % 360;
      glutPostRedisplay();
      break;  
    case 27:
      exit(0);
      break;
  }
}
