
#pragma once
#include <string>
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <vector>

class Mesh
{
public:
	Mesh();
	~Mesh();
	void CreateMesh(GLint vertexCount); 
	void Draw(GLenum primitive); 
	void SetPositionAttribute(std::vector<glm::vec2> positions, GLenum usage, GLuint locationIndex);
	void SetPositionAttribute(std::vector<glm::vec3> positions, GLenum usage, GLuint locationIndex); 
	void SetColorAttribute(std::vector<glm::vec3> colors, GLenum usage, GLuint locationIndex);
	void SetColorAttribute(std::vector<glm::vec4> colors, GLenum usage, GLuint locationIndex);
	void SetIndices(std::vector<unsigned int> indices, GLenum usage); //una lista que guarda numeros enteros sin signo 
	
private:
	void SetAttributeData(GLuint& buffer, const GLsizeiptr size, const void* data, GLenum usage, GLuint locationIndex, const GLint components);
	
	GLuint _vertexArrayObject = 0;
	GLuint _positionsVertexBufferObject = 0;
	GLuint _colorsVertexBufferObject = 0;
	GLuint _indicesBufferObject = 0;
	GLint _vertexCount = 0;
	GLint _indicesCount = 0;

};

//Cuadrado con GL_TRIANGLES. Sin indices seria 6 vertices 
//positions.pushback (V0) 
//indices.pushback 
//24 posiciones, 6 indices por cada cara 
//trabajar de 4 en 4
//los cuatro colores encajan con las cuatro posiciones 
//mover la camara en z+ para ver el cubo de frente 
