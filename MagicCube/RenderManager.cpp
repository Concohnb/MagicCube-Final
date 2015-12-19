
#include "Screen.h"
#include "Render.h"

camera Camera;

GLFWwindow* window;

screens Screen;

void initCallBack();
void initShader();

int initGL()
{
	//��ʼ��GLFW
	if (!glfwInit())
		return -1;

	//��������
	window = glfwCreateWindow(640, 480, "Magic Cube", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -2;
	}

	//�ô��廷����ȷ
	glfwMakeContextCurrent(window);

	//��ʼ��GLEW
	if (glewInit() != GLEW_OK)
		return -3;

	initShader();
	initCallBack();

	//��ʼ��Opengl��һЩ����
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);

	glfwSetWindowSize(window, 870, 512);
	
	return true;
}
int renderMainLoop()
{
	while (!glfwWindowShouldClose(window))
	{
		//��Ⱦ
		Screen.drawScreen();
		//��������
		glfwSwapBuffers(window); 

		//�����û�����
		glfwPollEvents();
	}
	//����
	glfwTerminate();

	return 0;
}