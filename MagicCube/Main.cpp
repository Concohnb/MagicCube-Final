
#include "World.h"
#include "Block.h"

#include "Screen.h"

int initGL();
int renderMainLoop();

int main()
{
	chunks Chunk;
	//��ʼ��OpenGL
	initGL();

	//���һ����Ļ���Ҽ���
	Screen.enableScreen(Screen.addScreen());

	//��ȡ�µ�RenderGroup��ָ��
	renderGroup* RenderGroup = Screen.addRenderGroup();

	//����Shader
	RenderGroup->setShader(&Shader[0]);
	std::vector<GLfloat> RenderData;

	RenderData.reserve(100);
	//�ṩ��Ⱦ����
	RenderData.push_back(-0.5);
	RenderData.push_back(0.5);
	RenderData.push_back(-1.0);
	RenderData.push_back(-0.5);
	RenderData.push_back(-0.5);
	RenderData.push_back(-1.0);
	RenderData.push_back(0.5);
	RenderData.push_back(-0.5);
	RenderData.push_back(-1.0);
	RenderData.push_back(0.5);
	RenderData.push_back(0.5);
	RenderData.push_back(-1.0);
	//OK��

	//��������
	RenderGroup->setData(&RenderData);
	//������Ⱦ��
	RenderGroup->IsEnable = true;

	//��Ⱦ��ѭ��
	return renderMainLoop();
}