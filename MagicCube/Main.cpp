#include "World.h"
#include "Block.h"

#include "Render.h"

int initGL();
int renderMainLoop();

int main()
{
	//��ʼ��OpenGL
	initGL();
	//����һ��Shader������Shader���ͣ��Ժ���ܲ���Ҫ��ע���ͣ�
	shader Normal2D("Normail2D", 0);

	//���һ����Ļ���Ҽ���
	Screen.enableScreen(Screen.addScreen());

	//��ȡ�µ�RenderGroup��ָ��
	renderGroup* RenderGroup = Screen.addRenderGroup();

	//����Shader
	RenderGroup->setShader(Normal2D);
	std::vector<GLfloat> RenderData;

	//�ṩ��Ⱦ����
	RenderData.push_back(-1.0);
	RenderData.push_back(1.0);
	RenderData.push_back(0.0);
	RenderData.push_back(-1.0);
	RenderData.push_back(-1.0);
	RenderData.push_back(0.0);
	RenderData.push_back(1.0);
	RenderData.push_back(-1.0);
	RenderData.push_back(0.0);
	RenderData.push_back(1.0);
	RenderData.push_back(1.0);
	RenderData.push_back(0.0);
	//OK��

	//��������
	RenderGroup->setData(RenderData);
	//������Ⱦ��
	RenderGroup->IsEnable = true;
	//�ڶ�����Ļ
	//���һ����Ļ���Ҽ���
	Screen.enableScreen(Screen.addScreen());

	//��ȡ�µ�RenderGroup��ָ��
	RenderGroup = Screen.addRenderGroup();

	//����Shader
	RenderGroup->setShader(Normal2D);
	RenderData.clear();

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
	RenderGroup->setData(RenderData);
	//������Ⱦ��
	RenderGroup->IsEnable = true;

	//��Ⱦ��ѭ��
	return renderMainLoop();
}