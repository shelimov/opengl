#include "shaderUtils.h"

std::string loadShader(const std::string& fileName) {
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

void checkShaderErrors(GLuint shader, GLuint flag, bool isProgram, const std::string& buff) {
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
