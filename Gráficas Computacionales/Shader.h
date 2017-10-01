/***********************************************

Materia: Gráficas Computacionales
Fecha: 2 de octubre del 2017
Autor: A01375351 Diana Isabel Hernández María

*************************************************/
#pragma once
#include <string>
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <vector>

class Shader {

public:
	Shader();
	~Shader();
	void CreateShader(std::string path, GLenum type);
	GLuint GetHandle();

private:
	GLuint _shaderHandle = 0;
};
