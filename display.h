#ifndef DISPLAY_H
#define DISPLAY_H

#define CPLUS_INCLUDE_PATH "/usr/local/include/"
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <string>
#include <iostream>

class Display {
public:
  Display(const int width, const int height, const std::string& title);
  void update();
  bool isClosed();

  virtual ~Display();
protected:
private:
  Display(const Display& other) {};
  void operator=(const Display& other) {};

  SDL_Window* m_window;
  SDL_GLContext m_glContext;
  bool m_isClosed;
};
#endif
