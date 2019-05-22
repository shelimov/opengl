#include "display.h"

Display::Display(const int width, const int height, const std::string& title) {
  if (!glfwInit()) {
    std::cerr << "GLFW failed to initialize!" << std::endl;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
  glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
  const GLFWvidmode *mode = glfwGetVideoMode(primaryMonitor);
  m_window = glfwCreateWindow(mode->width, mode->height, title.c_str(), glfwGetPrimaryMonitor(), NULL);

  if (!m_window) {
    glfwTerminate();
    std::cerr << "GLFW failed to create window!" << std::endl;
  }

  glfwMakeContextCurrent(m_window);

  GLenum status = glewInit();

  if (status != GLEW_OK) {
    std::cerr << "Glew failed to initialize!" << std::endl;
  }

  std::cout << "Version of OpenGL initialized: " << glGetString(GL_VERSION)
    << '\n' << "Version of OpenGL Shading Language " << glGetString(GL_SHADING_LANGUAGE_VERSION)
    << std::endl;
}

Display::~Display() {
  glfwDestroyWindow(m_window);
  glfwTerminate();
}

bool Display::shouldClose() {
  return glfwWindowShouldClose(m_window);
}

void Display::update() {
  glfwSwapBuffers(m_window);
  glfwPollEvents();
}
