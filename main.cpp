#include "main.h"

const float FPS = 120.0;
const float msPerFrame = 1000.0 / FPS;
double prevTime = 0.0;
GLuint vao[1];
GLuint program;

void init() {
  const std::string vertexShaderCode = loadShader("shaders/basicShader.vs");
  const std::string fragmentShaderCode = loadShader("shaders/basicShader.fs");
  GLuint vert = glCreateShader(GL_VERTEX_SHADER);
  GLuint frag = glCreateShader(GL_FRAGMENT_SHADER);
  const char* vs_c_str = vertexShaderCode.c_str();
  const char* fs_c_str = fragmentShaderCode.c_str();
  glShaderSource(vert, 1, &vs_c_str, NULL);
  glShaderSource(frag, 1, &fs_c_str, NULL);
  glCompileShader(vert);
  std::string buff;
  checkShaderErrors(vert, GL_COMPILE_STATUS, false, buff);
  glCompileShader(frag);
  checkShaderErrors(vert, GL_COMPILE_STATUS, false, buff);


  program = glCreateProgram();
  glAttachShader(program, vert);
  glAttachShader(program, frag);
  glLinkProgram(program);
  glDeleteShader(vert);
  glDeleteShader(frag);
  glGenVertexArrays(1, vao);
  glBindVertexArray(vao[0]);
}

void gameLoop(double secondsPassed) {
  const GLfloat color[] = {
    (float)sin(secondsPassed) * 0.5f + 0.5f,
    (float)cos(secondsPassed) * 0.5f + 0.5f,
    0.0f,
    1.0f
  };
  glClearBufferfv(GL_COLOR, 0, color);
  glUseProgram(program);
  glDrawArrays(GL_TRIANGLES, 0, 3);
}

int main(int argc, char *argv[]) {
  Display display(1024, 768, "OpenGL sandbox");
  init();

  while (!display.shouldClose()) {
    double currentTime = glfwGetTime() * 1000;
    double timeDiff = currentTime - prevTime;
    if (timeDiff < msPerFrame) continue;
    prevTime = currentTime;

    gameLoop(currentTime / 1000);
    display.update();
  }
  return 0;
}
