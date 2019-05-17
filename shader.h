#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <iostream>
#include <fstream>
#include <GL/glew.h>

static std::string loadShader(const std::string& fileName);
static void checkShaderErrors(GLuint shader, GLuint flag, bool isProgram, const std::string& buff);
static GLuint createShader(const std::string& text, GLenum type);

class Shader {
public:
  Shader(const std::string& fileName);

  void bind();

  virtual ~Shader();

protected:
private:
  static const unsigned int NUM_SHADERS = 2;
  Shader(const Shader& other) {};
  void operator=(const Shader& other) {};

  GLuint m_program;
  GLuint m_shaders[NUM_SHADERS];

};

#endif
