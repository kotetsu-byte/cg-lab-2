#pragma once	
#include <GL/glew.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

class Shader
{
public:
	GLuint ID;

	Shader(const char* vertexPath, const char* fragmentPath);
	void use() const { 
		glUseProgram(ID); 
	}
	void deleteProgram() {
		glDeleteProgram(ID);
	}
	void setUniform(const string& name, float v1);
	void setUniform(const string& name, float v1, float v2);
	void setUniform(const string& name, float v1, float v2, float v3);
	void setUniform(const string& name, float v1, float v2, float v3, float v4);

private:
	string loadShaderSource(const char* shaderPath);
	GLuint compileShader(GLenum shaderType, const char* source);
};