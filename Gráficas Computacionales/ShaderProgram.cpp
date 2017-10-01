/***********************************************

Materia: Gr�ficas Computacionales
Fecha: 2 de octubre del 2017
Autor: A01375351 Diana Isabel Hern�ndez Mar�a

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

void ShaderProgram::LinkProgram() //DUDAAAAAS 
{
	
	glAttachShader(_programHandle, _attachedShaders.push_back); //preguntar esta linea. Tienen que ser  dos, uno para el frag y otro para el vert 
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

void ShaderProgram::DeleteAndDetachShaders() //DUDAAAAAAS
{
	glDetachShader(_programHandle, _attachedShaders.push_back); //preguntar esta linea. Tienen que ser  dos, uno para el frag y otro para el vert 
	
	_attachedShaders.push_back->delete_all(); // esto es para eliminar todos los nodos de una lista 
	_attachedShaders.push_back = 0;

	glDeleteShader(_attachedShaders.push_back); //revisar si esta bien esta linea para borrar la lista 
	
    //revisar cual de las dos lineas para borrar la lista es la correcta 
}

void ShaderProgram::DeleteProgram()
{
	DeleteAndDetachShaders();
	glDeleteProgram(_programHandle);
}
