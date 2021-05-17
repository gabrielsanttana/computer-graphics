#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>

static int rotationX = -30;
static int rotationY = 0;
static double zoom = 1;
int aspectRatio;

void init(void) {
  glClearColor (0.0, 0.0, 0.0, 0.0);
}

void display(void) {
  glClear (GL_COLOR_BUFFER_BIT);
  glPushMatrix();
  
  glRotatef((GLfloat)rotationX, 0.0, 1.0, 0.0);
  glRotatef((GLfloat)rotationY, 1.0, 0.0, 0.0);
  glScalef(zoom, zoom, 1.0f);
  
  double chaoX = 0.0;
  double chaoY = 0.0;
  double chaoZ = 0.0;
   
  // Gramado
  glColor3f(0.0f, 1.0f, 0.0f);
  glPushMatrix();
  glTranslatef (chaoX, chaoY, chaoZ);
  glScalef (70.0, 1.0, 100.0);
  glutSolidCube (1.0);
  glPopMatrix();  
   
  // Pista de pouso
  glPushMatrix();
  glColor3f(0.0f, 0.0f, 0.0f);
  glTranslatef (chaoX, chaoY, chaoZ);
  glScalef (15.0, 1.0, 100.0);
  glutSolidCube (1.0);
  glPopMatrix();
  
  // Torre
  GLUquadricObj *quadric = gluNewQuadric();

  glColor4f(1.0, 1.0, 1.0, 0.6);
  glPushMatrix();
  glTranslatef (chaoX+31, chaoY, chaoZ-46);
  glScalef(5, 1, 5);
  glRotatef(-120,1.0,1.0,1.0);
  gluCylinder(quadric,1,1,50,250,250);
  glPopMatrix();
  
  // Janela torre de comando
  glPushMatrix();
  glColor3f(0.5f, 1.0f, 1.0f);
  glTranslatef (chaoX+31, chaoY+41, chaoZ-46);
  glRotatef (90,1, chaoY, chaoZ);
  glScalef (7.5, 7.5, 3);
  glutSolidTorus(1,1,250, 250);
  glPopMatrix();
  
  // Parte Superior da torre de comando
  glPushMatrix();
  glColor3f(0.3f, 0.3f, 0.3f);
  glTranslatef (chaoX+31, chaoY+40, chaoZ-46);
  glRotatef (90,1, chaoY, chaoZ);
  glScalef (7, 7, 7.0);
  glutSolidTorus(1,1,250, 250);
  glPopMatrix();

  // Hangar
  glPushMatrix();
  glColor3f(0.0f, 0.0f, 1.0f);
  glTranslatef (chaoX-25, chaoY+15, chaoZ);
  glScalef (20.0, 30, 60.0);
  glutSolidCube (1.0);
  glPopMatrix();   
    
  // Portao Hangar
  glPushMatrix();
  glColor3f(1.0f, 1.0f, 1.0f);
  glTranslatef (chaoX-15, chaoY+13, chaoZ);
  glScalef (2, 26, 40.0);
  glutSolidCube (1.0);
  glPopMatrix(); 
  
  // Tartaruga 1
  glPushMatrix();
  glColor3f(1.0f, 1.0f, 1.0f);
  glTranslatef (chaoX, chaoY, chaoZ);
  glScalef (2.0, 0.1, 10.0);
  glutSolidCube (1.0);
  glPopMatrix();
    
  // Tartaruga 2
  glPushMatrix();
  glColor3f(1.0f, 1.0f, 1.0f);
  glTranslatef (chaoX, chaoY, chaoZ -20);
  glScalef (2.0, 0.1, 10.0);
  glutSolidCube (1.0);
  glPopMatrix();
  
  // Tartaruga 3
  glPushMatrix();
  glColor3f(1.0f, 1.0f, 1.0f);
  glTranslatef (chaoX, chaoY, chaoZ -40);
  glScalef (2.0, 0.1, 10.0);
  glutSolidCube (1.0);
  glPopMatrix(); 
  
  // Tartaruga 4
  glPushMatrix();
  glColor3f(1.0f, 1.0f, 1.0f);
  glTranslatef (chaoX, chaoY, chaoZ +20);
  glScalef (2.0, 0.1, 10.0);
  glutSolidCube (1.0);
  glPopMatrix();
  
  // Tartaruga 5
  glPushMatrix();
  glColor3f(1.0f, 1.0f, 1.0f);
  glTranslatef (chaoX, chaoY, chaoZ +40);
  glScalef (2.0, 0.1, 10.0);
  glutSolidCube (1.0);
  glPopMatrix(); 
  glPopMatrix();
  glutSwapBuffers();
}

void reshape (int w, int h) {
  aspectRatio = (GLfloat) w/(GLfloat) h;
  glViewport(0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(65, aspectRatio, 1.0, 200.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0, -15, -100.0);
}

void keyboard(unsigned char key, int x, int y) {
  switch (key) {
    case 'a':
      rotationX = (rotationX + 6) % 360;
      glutPostRedisplay();
      break;

    case 'd':
      rotationX = (rotationX - 6) % 360;
      glutPostRedisplay();
      break;

    case 'w':
      rotationY = (rotationY + 6) % 360;
      glutPostRedisplay();
      break;

    case 's':
      rotationY = (rotationY - 6) % 360;
      glutPostRedisplay();
      break;

    case 'z':
      zoom = (zoom - 0.06);
      glutPostRedisplay();
      break;

    case 'Z':
      zoom = (zoom + 0.06);
      glutPostRedisplay();
      break;

    case 27:
	    exit(0);
  	  break;
  }
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(500, 500); 
  glutInitWindowPosition(100, 100);
  glutCreateWindow(argv[0]);
  init();
  glutDisplayFunc(display); 
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMainLoop();

  return 0;
}
