#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <string>
#include <iostream>
#include <fstream>

static std::string loadShader(const std::string& fileName);
static void checkShaderErrors(GLuint shader, GLuint flag, bool isProgram, const std::string& buff);

#endif
