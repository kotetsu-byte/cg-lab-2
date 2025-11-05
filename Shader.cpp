#include "Shader.h"

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
	string vertexCode = loadShaderSource(vertexPath);
	string fragmentCode = loadShaderSource(fragmentPath);
	const char* vShaderCode = vertexCode.c_str();
	const char* fShaderCode = fragmentCode.c_str();

	GLuint vertex = compileShader(GL_VERTEX_SHADER, vShaderCode);
	GLuint fragment = compileShader(GL_FRAGMENT_SHADER, fShaderCode);

	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);

	GLint success;
	GLchar infoLog[1024];
	glGetProgramiv(ID, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(ID, 1024, NULL, infoLog);
		cerr << "Shader linking error:\n" << infoLog << endl;
	}

	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

string Shader::loadShaderSource(const char* shaderPath)
{
	ifstream file(shaderPath);
	stringstream buffer;
	buffer << file.rdbuf();
	return buffer.str();
}

GLuint Shader::compileShader(GLenum shaderType, const char* source)
{
	GLuint shader = glCreateShader(shaderType);
	glShaderSource(shader, 1, &source, NULL);
	glCompileShader(shader);

	GLint success;
	GLchar infoLog[1024];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 1024, NULL, infoLog);
		cerr << "Shader compilation error (" 
			<< (shaderType == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT")
			<< "):\n" << infoLog << endl;
	}
	return shader;
}

void Shader::setUniform(const std::string& name, float v1) {
	glUniform1f(glGetUniformLocation(ID, name.c_str()), v1);
}
void Shader::setUniform(const std::string& name, float v1, float v2) {
	glUniform2f(glGetUniformLocation(ID, name.c_str()), v1, v2);
}
void Shader::setUniform(const std::string& name, float v1, float v2, float v3) {
	glUniform3f(glGetUniformLocation(ID, name.c_str()), v1, v2, v3);
}
void Shader::setUniform(const std::string& name, float v1, float v2, float v3, float v4) {
	glUniform4f(glGetUniformLocation(ID, name.c_str()), v1, v2, v3, v4);
}