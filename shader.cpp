#include "shader.h"

Shader::Shader(const std::string& fileName) {
  m_program = glCreateProgram();
  m_shaders[0] = createShader(loadShader(fileName + ".vs"), GL_VERTEX_SHADER);
  m_shaders[1] = createShader(loadShader(fileName + ".fs"), GL_FRAGMENT_SHADER);

  for (unsigned int i = 0; i < NUM_SHADERS; i++) {
    glAttachShader(m_program, m_shaders[i]);
  }

  glBindAttribLocation(m_program, 0, "position");

  glLinkProgram(m_program);
  checkShaderErrors(m_program, GL_LINK_STATUS, true, "Program linking failed");

  glValidateProgram(m_program);
  checkShaderErrors(m_program, GL_VALIDATE_STATUS, true, "Program is invalid");
}

Shader::~Shader() {
  for (unsigned int i = 0; i < NUM_SHADERS; i++) {
    glDetachShader(m_program, m_shaders[i]);
    glDeleteShader(m_shaders[i]);
  }
  glDeleteProgram(m_program);
}

void Shader::bind() {
  glUseProgram(m_program);
}

static std::string loadShader(const std::string& fileName) {
  std::ifstream file;
  file.open(fileName.c_str());

  std::string line;
  std::string output;

  if (file.is_open()) {
    while (!file.eof()) {
      getline(file, line);
      output.append(line + "\n");
    }
  } else {
    std::cerr << "An error occured, while reading shader file" << std::endl;
  }

  file.close();

  return output;
}

static GLuint createShader(const std::string& text, GLenum type) {
  GLuint shader = glCreateShader(type);

  if (shader == 0) {
    std::cerr << "Error: shader creation failed!" << std::endl;
  }

  const GLchar* shaderSourceStrings[1];
  GLint shaderSourceStringLengths[1];


  shaderSourceStrings[0] = text.c_str();
  shaderSourceStringLengths[0] = text.length();

  glShaderSource(shader, 1, shaderSourceStrings, shaderSourceStringLengths);
  glCompileShader(shader);

  checkShaderErrors(shader, GL_COMPILE_STATUS, false, "Error: shader compilation failed");

  return shader;
}

static void checkShaderErrors(GLuint shader, GLuint flag, bool isProgram, const std::string& buff) {
  GLint success = 0;
  GLchar error[1024] = { 0 };

  if (isProgram) {
    glGetProgramiv(shader, flag, &success);
  } else {
    glGetShaderiv(shader, flag, &success);
  }

  if(success == GL_FALSE) {
    if (isProgram) {
      glGetProgramInfoLog(shader, sizeof(error), NULL, error);
    } else {
      glGetShaderInfoLog(shader, sizeof(error), NULL, error);
    }

    std::cerr << buff << "\n" << error << std::endl;
  }
}
