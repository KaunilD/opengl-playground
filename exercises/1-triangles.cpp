#include "glimports.h"
#include "LoadShaders.h"

enum VAO_IDs { Triangles, NumVAOs };
enum Buffer_IDs { ArrayBuffer, NumBuffers };
enum Attrib_IDs { vPosition = 0 };

GLuint VAOs[NumVAOs];
GLuint Buffers[NumBuffers];

const GLuint  NumVertices = 6;


void display(void) {
	static const float black[] = { 0.0f, 0.0f, 0.0f, 0.0f };
	glClearBufferfv(GL_COLOR, 0, black);
	glBindVertexArray(VAOs[Triangles]);
	glDrawArrays(GL_TRIANGLES, 0, NumVertices);
}

void init(void) {
	GLfloat vertices[NumVertices][2] = 
	{
		{ -0.90f, -0.90f },  // Triangle 1
		{  0.85f, -0.90f },
		{ -0.90f,  0.85f },
		{  0.90f, -0.85f },  // Triangle 2
		{  0.90f,  0.90f },
		{ -0.85f,  0.90f }
	};

	glCreateVertexArrays(NumVAOs, VAOs);
	glBindVertexArray(VAOs[Triangles]);

	glCreateBuffers(NumBuffers, Buffers);
	glBindBuffer(GL_ARRAY_BUFFER, Buffers[ArrayBuffer]);

	glBufferStorage(
		GL_ARRAY_BUFFER, 
		sizeof(vertices), vertices, 
		0
	);

	ShaderInfo shaders[] = {
		{ GL_VERTEX_SHADER, "media/shaders/triangles/triangles.vert" },
		{ GL_FRAGMENT_SHADER, "media/shaders/triangles/triangles.frag" },
		{ GL_NONE, NULL }
	};

	GLuint program = LoadShaders(shaders);
	glUseProgram(program);


	glVertexAttribPointer(
		vPosition, 
		2, 
		GL_FLOAT,
		GL_FALSE, 
		0, 
		0
	);

	glEnableVertexAttribArray(vPosition);
}


int main(int argc, char** argv) {
	
	glfwInit();
	
	GLFWwindow* window = glfwCreateWindow(
		640, 480, 
		"Triangles", 
		NULL, NULL
	);
	
	glfwMakeContextCurrent(window);
	
	gl3wInit();

	init();

	while (!glfwWindowShouldClose(window)) {
		display();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}