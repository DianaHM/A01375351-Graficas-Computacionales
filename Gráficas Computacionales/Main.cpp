#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Employee.h"
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <vector>

GLuint vao; //Identificador del manage al que vamos a asociar todos los VBOs 

void Initialize() 
{
	std::vector<glm::vec2> positions;
	positions.push_back(glm::vec2(0.5f, 0.5f));
	positions.push_back(glm::vec2(-0.5f, 0.5f));
	positions.push_back(glm::vec2(0.5f, -0.5f));
	positions.push_back(glm::vec2(-0.5f, -0.5f));

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	GLuint positionsVBO; //Entero sin signo 
	glGenBuffers(1, &positionsVBO);
	glBindBuffer(GL_ARRAY_BUFFER, positionsVBO); //activar el buffer de posiciones para poder utilizarlo 
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2) * positions.size(), positions.data(), GL_STATIC_DRAW); //Creamos la memoria y la inicializamos con los datos del atributo de posiciones
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);//configuramos los datos del atributo en la tarjeta de video
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);
}

void GameLoop()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpiamos el buffer de control y el de profundidad. Siempre hacerlo al inicio del frame

	glBindVertexArray(vao); //activamos el mamager y con esto se activan todos los VBOs asociados automaticamente
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4); //funcion de dibujando sin indices 
	glBindVertexArray(0); //terminamos de utilizar el manager 

	//cuando terminamos de renderear cambiamos los buffers 
	glutSwapBuffers();
}

int main(int argc, char* argv[])
{

	glutInit(&argc, argv);
	glutInitContextVersion(4,5);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Hello World GL");
	glutDisplayFunc(GameLoop);
	glewInit();

	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);// la venta de OpenGL.
	std::cout << glGetString(GL_VERSION) << std::endl;
	Initialize();
	glutMainLoop();

	return 0;
}

/**
int main() {
	Circle circulo(2.0, "green");
	std::cout << circulo.GetColor() << std::endl;

	Rectangle rectangulo(5.0, 3.0);
	std::cout << rectangulo.GetArea() << std::endl;

	Employee empleado(8967, "Diana", "Hernandez", 1000);
	std::cout << empleado.Print() << std::endl;

	std::cin.get();
	return 0;
}
**/