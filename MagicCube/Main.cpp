
#include "Screen.h"
#include "Chunk.h"
//��ʼ��Chunk
chunks Chunk;

int initGL();
int renderMainLoop();
void initGame();

int main()
{
	//��ʼ��OpenGL
	initGL();

	//���һ����Ļ���Ҽ���
	Screen.enableScreen(Screen.addScreen(true));

	//��ȡ�µ�RenderGroup��ָ��
	renderGroup* RenderGroup = Screen.addRenderGroup();

	//����Shader
	RenderGroup->setShader(&Shader[0]);
	std::vector<GLfloat> RenderData;

	RenderData.reserve(100);
	//�ṩ��Ⱦ����
	RenderData.push_back(-0.5);
	RenderData.push_back(0.5);
	RenderData.push_back(0.0);
	RenderData.push_back(-0.5);
	RenderData.push_back(-0.5);
	RenderData.push_back(0.0);
	RenderData.push_back(0.5);
	RenderData.push_back(-0.5);
	RenderData.push_back(0.0);
	RenderData.push_back(0.5);
	RenderData.push_back(0.5);
	RenderData.push_back(0.0);
	//OK��

	//��������
	RenderGroup->setData(&RenderData);
	//������Ⱦ��
	RenderGroup->IsEnable = true;

	//��ʼ����Ϸ
	initGame();

	//��Ⱦ��ѭ��
	return renderMainLoop();
}