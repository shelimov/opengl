#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "display.h"
#include "./shaders/shaderUtils.h"

std::clock_t prevTime = 0;
const double CLOCKS_PER_MS = CLOCKS_PER_SEC / 1000.0;
const float FPS = 120.0;
const float msPerFrame = 1000.0 / FPS;

void init() {

}

void gameLoop(Display& d, float timePassed) {
  const GLfloat color[] = { (float)sin(timePassed) * 0.5f + 0.5f,
                            (float)cos(timePassed) * 0.5f + 0.5f,
                            0.0f,
                            1.0f
                          };
  glClearColor(color[0], color[1], color[2], color[3]);
  glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char *argv[]) {
  Display display(1024, 768, "OpenGL sandbox");
  init();

  while (!display.isClosed()) {
    std::clock_t currentTime = clock() / CLOCKS_PER_MS;
    std::clock_t timeDiff = (currentTime - prevTime);
    if (timeDiff < msPerFrame) continue;
    prevTime = currentTime;
    gameLoop(display, currentTime / 1000.0);

    display.update();
  }
  return 0;
}
