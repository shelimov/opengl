#ifndef DISPLAY_H
#define DISPLAY_H
#define CPLUS_INCLUDE_PATH "/usr/local/include/"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>

class Display {
public:
  Display(const int width, const int height, const std::string& title);
  void update();
  bool shouldClose();

  virtual ~Display();
protected:
private:
  Display(const Display& other) {};
  void operator=(const Display& other) {};

  GLFWwindow* m_window;
};
#endif
