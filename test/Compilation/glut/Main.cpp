#include <GLUT/glut.h>
#include <OpenGL/glu.h>
#include <OpenGL/glext.h>
#include <stdio.h>
#include <stdlib.h>

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glRectf(-0.5, -0.5, 0.5, 0.5);
  glutSwapBuffers();
}

void close()
{
    glutDestroyWindow(0);
    exit(0);
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutCreateWindow(argv[0]);
  glutWMCloseFunc(close);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}