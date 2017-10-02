/***********************************************

Materia: Gráficas Computacionales
Fecha: 2 de octubre del 2017
Autor: A01375351 Diana Isabel Hernández María

*************************************************/

#include "ShaderProgram.h"
#include "Shader.h"
#include "memory"

ShaderProgram::ShaderProgram()
{
	_programHandle = 0;
	_attachedShaders;
}

ShaderProgram::~ShaderProgram()
{
	DeleteProgram();
}

void ShaderProgram::CreateProgram()
{
	_programHandle = glCreateProgram();
}

void ShaderProgram::AttachShader(std::string path, GLenum type)
{
	std::unique_ptr<Shader> shader(new Shader);
	shader->CreateShader(path, type);
	_attachedShaders.push_back(std::move(shader)); 
}

void ShaderProgram::LinkProgram() 
{
	
	glAttachShader(_programHandle, _attachedShaders.push_back); 
	glLinkProgram(_programHandle); 

	DeleteAndDetachShaders();
}

void ShaderProgram::Activate()
{
	glBindVertexArray(_programHandle); 	
}

void ShaderProgram::Deactivate()
{

	glBindVertexArray(0); 

}

void ShaderProgram::SetAttribute(GLuint locationIndex, std::string name)
{
	const GLchar *nombre = (const GLchar*) name.c_str;
	glBindAttribLocation(_programHandle, locationIndex, nombre);
}
void ShaderProgram::SetUniformf(std::string name, float value)
{
	glUseProgram(_programHandle);
	const GLchar  *nombre = (const GLchar*)name.c_str;
	GLint uniformLocation = glGetUniformLocation(_programHandle, nombre);
	glUniform1f(uniformLocation, value);
	glUseProgram(0);
}

void ShaderProgram::SetUniformf(std::string name, float x, float y)
{
	glUseProgram(_programHandle);
	const GLchar  *nombre = (const GLchar*)name.c_str;
	GLint uniformLocation = glGetUniformLocation(_programHandle, nombre);
	glUniform2f(uniformLocation, x, y);
	glUseProgram(0);
}

void ShaderProgram::SetUniformf(std::string name, float x, float y, float z)
{
	glUseProgram(_programHandle);
	const GLchar  *nombre = (const GLchar*)name.c_str;
	GLint uniformLocation = glGetUniformLocation(_programHandle, nombre);
	glUniform3f(uniformLocation, x, y, z);
	glUseProgram(0);
}

void ShaderProgram::SetUniformf(std::string name, float x, float y, float z, float w)
{
	glUseProgram(_programHandle);
	const GLchar  *nombre = (const GLchar*)name.c_str;
	GLint uniformLocation = glGetUniformLocation(_programHandle, nombre);
	glUniform4f(uniformLocation, x, y, z, w);
	glUseProgram(0);
}

void ShaderProgram::DeleteAndDetachShaders()
{

	for (int i = 0; i < _attachedShaders.size(); i++) {
		glDetachShader(_programHandle, _attachedShaders.back);
		_attachedShaders.pop_back();
	}
	
	glDeleteShader(_attachedShaders.push_back); 
	
}

void ShaderProgram::DeleteProgram()
{
	DeleteAndDetachShaders();
	glDeleteProgram(_programHandle);
}
