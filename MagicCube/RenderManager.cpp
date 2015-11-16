
#include "Render.h"

GLFWwindow* window;

void initCallBack();
void initShaders();

int initGL()
{
	//��ʼ��GLFW
	if (!glfwInit())
		return -1;

	//��������
	window = glfwCreateWindow(640, 480, "TEST", NULL, NULL);

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

	initShaders();
	initCallBack();

	glfwSetWindowSize(window, 870, 512);
	
	return true;
}
int renderMainLoop()
{
	while (!glfwWindowShouldClose(window))
	{
		//��Ⱦ

		//��������
		glfwSwapBuffers(window); 

		//�����û�����
		glfwPollEvents();
	}
	//����
	glfwTerminate();

	return 0;
}