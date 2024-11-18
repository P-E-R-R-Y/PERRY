#include <GLUT/glut.h>
#include <OpenGL/glu.h>
#include <OpenGL/glext.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glRectf(-0.5, -0.5, 0.5, 0.5);
  glutSwapBuffers();
}

void close()
{
    glutDestroyWindow(0);
    std::cout << "close" << std::endl;
}

int windowId;

int main(void)
{
  //glutInit without acces to ac and av ?
  int argc = 0;
  char *argv[] = { 0 };
  glutInit(&argc, argv);
  //glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  windowId = glutCreateWindow(argv[0]);
  glutWMCloseFunc(close);
  glutDisplayFunc(display);
  glutKeyboardFunc([](unsigned char key, int x, int y) {
    if (key == 27)
      glutDestroyWindow(windowId);
      exit(0);
  });
  glutMainLoop();
  return 0;
}