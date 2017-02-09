#include "shader.h"
#include <iostream>
#include <fstream>


Shader::Shader(const std::string &fileName)
{
	m_program = glCreateProgram();
	m_shaders[0] = CreateShader(LoadShader(fileName + ".vs"),GL_VERTEX_SHADER);
	m_shaders[1] = CreateShader(LoadShader(fileName + ".fs"), GL_FRAGMENT_SHADER);
	for (unsigned int i = 0; i < NUM_SHADER; i++) 
		glAttachShader(m_program, m_shaders[i]);
	glBindAttribLocation(m_program, 0, "position");

	glLinkProgram(m_program);
	CheckShaderError(m_program, GL_LINK_STATUS, true, "Error: program linking failed");

	glValidateProgram(m_program);
	CheckShaderError(m_program, GL_LINK_STATUS, true, "Error: program validete failed");
}


 Shader::~Shader()
{
	 for (unsigned int i = 0; i < NUM_SHADER; i++) {
		 glDetachShader(m_program, m_shaders[i]);
		 glDeleteShader(m_shaders[i]);
	 }
	 glDeleteProgram(m_program);
}

 void Shader::Bind() {
	 glUseProgram(m_program);
 }





 GLuint Shader::CreateShader(const std::string &text, GLenum shaderType) {
	 GLuint shader = glCreateShader(shaderType);
	 if (shader == 0) {
		 std::cout << "Error:shader create failed" << std::endl;
	 }
	 const GLchar* shaderSourceString[1];
	 GLint shaderSourceStringLength[1];
	 shaderSourceString[0] = text.c_str();
	 shaderSourceStringLength[0] = text.length;
	 glShaderSource(shader, 1, shaderSourceString, shaderSourceStringLength);
	 glCompileShader(shader);
	 CheckShaderError(shader, GL_COMPILE_STATUS, false,"Error: Shader Complie failed");
	 return shader;
 }
 std::string Shader::LoadShader(const std::string& fileName)
 {
	 std::ifstream file;
	 file.open((fileName).c_str());

	 std::string output;
	 std::string line;

	 if (file.is_open())
	 {
		 while (file.good())
		 {
			 getline(file, line);
			 output.append(line + "\n");
		 }
	 }
	 else
	 {
		 std::cerr << "Unable to load shader: " << fileName << std::endl;
	 }

	 return output;
 }

 void Shader::CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage)
 {
	 GLint success = 0;
	 GLchar error[1024] = { 0 };

	 if (isProgram)
		 glGetProgramiv(shader, flag, &success);
	 else
		 glGetShaderiv(shader, flag, &success);

	 if (success == GL_FALSE)
	 {
		 if (isProgram)
			 glGetProgramInfoLog(shader, sizeof(error), NULL, error);
		 else
			 glGetShaderInfoLog(shader, sizeof(error), NULL, error);

		 std::cerr << errorMessage << ": '" << error << "'" << std::endl;
	 }
 }