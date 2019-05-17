#include <iostream>
#include <cstdlib>
#include <ctime>
#include "display.h"
#include "shader.h"

void gameLoop(Display& d) {
  d.clear();
}

int main(int argc, char *argv[]) {
  Display display(1024, 768, "OpenGL sandbox");
  Shader shader("./shaders/basicShader");

  while (!display.isClosed()) {
    gameLoop(display);

    display.update();
  }
  return 0;
}
