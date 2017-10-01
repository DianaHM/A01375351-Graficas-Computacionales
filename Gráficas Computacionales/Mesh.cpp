/***********************************************

Materia: Gráficas Computacionales 
Fecha: 2 de octubre del 2017
Autor: A01375351 Diana Isabel Hernández María 

*************************************************/
#include "Mesh.h"



Mesh::Mesh()
{
	_vertexArrayObject = 0;
	_positionsVertexBufferObject = 0;
	_colorsVertexBufferObject = 0;
	_vertexCount = 0; 
}

Mesh::~Mesh()
{
	glDeleteBuffers( 1, &_positionsVertexBufferObject);
	glDeleteBuffers(1, &_colorsVertexBufferObject);
	glDeleteVertexArrays(1, &_vertexArrayObject);

}

void Mesh::CreateMesh(GLint vertexCount)
{
	_vertexCount = vertexCount;
	glCreateVertexArrays(1, &_vertexArrayObject);
}

void Mesh::Draw(GLenum primitive)
{
	glBindVertexArray(_vertexArrayObject);
	glDrawArrays(primitive, 0, _vertexCount);
	glBindVertexArray(0);
}

void Mesh::SetPositionAttribute(std::vector<glm::vec2> positions, GLenum usage, GLuint locationIndex)
{
	const GLsizeiptr sizepositions = sizeof(glm::vec2) * positions.size();
	const void* positiondata = positions.data();
	SetAttributeData(_positionsVertexBufferObject, sizepositions, positiondata, usage, locationIndex, 2 );
	
	// falta la condición 
}

void Mesh::SetColorAttribute(std::vector<glm::vec3> colors, GLenum usage, GLuint locationIndex)
{
	const GLsizeiptr sizecolors = sizeof(glm::vec3) * colors.size();
	const void* colorsdata = colors.data();
	SetAttributeData(_colorsVertexBufferObject, sizecolors, colorsdata, usage, locationIndex, 3);
	
	// falta la condición 
}

void Mesh::SetAttributeData(GLuint& buffer, const GLsizeiptr size, const void* data, GLenum usage, GLuint locationIndex, const GLint components)
{
	if (&buffer != 0) {
		glDeleteBuffers(1, &buffer);
	}
	else
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, size, data, usage);
	glEnableVertexAttribArray(locationIndex);
	glVertexAttribPointer(locationIndex, components, GL_FLOAT, GL_FALSE, 0, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	
}
