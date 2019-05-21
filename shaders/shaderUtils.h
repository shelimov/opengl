#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <string>
#include <iostream>
#include <fstream>

std::string loadShader(const std::string& fileName);
void checkShaderErrors(GLuint shader, GLuint flag, bool isProgram, const std::string& buff);

#endif
