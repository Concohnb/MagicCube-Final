
#include "Screen.h"

glm::mat4 GobalProjection = glm::perspective(45.0f, (GLfloat)640 / (GLfloat)480, 0.1f, 500.0f);
glm::mat4 GobalTranslate = glm::translate(glm::mat4(), glm::vec3(0.0, 0.0, 0.0));
glm::mat4 GobalRotate = glm::rotate_slow(glm::mat4(), 0.0f, glm::vec3(0.0f, 1.0f, 0.0f));

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

	initShader();
	initCallBack();

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