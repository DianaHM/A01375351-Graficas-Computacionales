#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <vector>
#include "Mesh.h"
#include "ShaderProgram.h"

Mesh _mesh;
ShaderProgram _shaderProgram;


void Initialize()
{
	std::vector<glm::vec2> positions;

	positions.push_back(glm::vec2(0.0f, 1.0f));
	positions.push_back(glm::vec2(0.0f, 0.5f));
	positions.push_back(glm::vec2(0.95f, 0.3f));
	positions.push_back(glm::vec2(0.45f, 0.18f));
	positions.push_back(glm::vec2(0.6f, -0.8f));
	positions.push_back(glm::vec2(0.3f, -0.4f));
	positions.push_back(glm::vec2(-0.6f, -0.8f));
	positions.push_back(glm::vec2(-0.3f, -0.4f));
	positions.push_back(glm::vec2(-0.95f, 0.3f));
	positions.push_back(glm::vec2(-0.45f, 0.18));
	positions.push_back(glm::vec2(0.0f, 1.0f));
	positions.push_back(glm::vec2(0.0f, 0.5f));

	std::vector<glm::vec3> colors;
	
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));

	_mesh.CreateMesh(12);
	_mesh.SetPositionAttribute(positions, GL_STATIC_DRAW, 0);
	_mesh.SetColorAttribute(colors, GL_STATIC_DRAW, 1); 

	_shaderProgram.CreateProgram();
	_shaderProgram.AttachShader("DiscardCenter.vert", GL_VERTEX_SHADER);
	_shaderProgram.AttachShader("DiscardCenter. frag", GL_FRAGMENT_SHADER);
	_shaderProgram.SetAttribute(0, "VertexPosition");
	_shaderProgram.SetAttribute(1, "VertexColor");
	_shaderProgram.LinkProgram();

}

void GameLoop()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpiamos el buffer de control y el de profundidad. Siempre hacerlo al inicio del frame

	_shaderProgram.Activate();
	_mesh.Draw(GL_TRIANGLE_STRIP);
	_shaderProgram.Deactivate();

	//Cuando terminamos de renderear cambiamos los buffers 
	glutSwapBuffers();
}

void Idle()
{
	glutPostRedisplay();
}

void ReshapeWindow(int width, int height)
{
	glViewport(0, 0, width, height);

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
	glutReshapeFunc(ReshapeWindow);
	glutIdleFunc(Idle);
	glewInit();

	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);// la venta de OpenGL.
	glEnable(GL_DEPTH_TEST); 
	glEnable(GL_CULL_FACE); 
	glCullFace(GL_BACK);

	std::cout << glGetString(GL_VERSION) << std::endl;
	Initialize();
	glutMainLoop();

	return 0;
}
