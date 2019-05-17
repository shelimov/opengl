#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "display.h"
#include "./shaders/shaderUtils.h"

std::clock_t prevTime = 0;
const double CLOCKS_PER_MS = CLOCKS_PER_SEC / 1000.0;
const float FPS = 60.0;
const float msPerFrame = 1000.0 / FPS;

void init() {

}

void gameLoop(Display& d, float timePassed) {
  std::cout << timePassed << std::endl;
  std::cout.flush();
  glClearColor(sin(timePassed), cos(timePassed), 1 - sin(timePassed), 1.0f);
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
