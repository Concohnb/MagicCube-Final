#pragma once

#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class renderGroup
{
	GLuint Shader = 0;
	GLuint Buffer = 0;
public:
	void setShader(GLuint Shader)
	{
		renderGroup::Shader = Shader;
	}
	void setData(GLfloat* RenderData)
	{
		glGenBuffers(1, &Buffer);
		glBindBuffer(GL_ARRAY_BUFFER, Buffer);

	}
	void draw()
	{

	}
};

class screen
{
	//ÿ�����������Σ���������Ϊ12(��״)+8(����)+16(��ɫ),����������Ժ��ڼ�
	std::vector<renderGroup> RenderGroup;
public:
	renderGroup* addRenderGroup()
	{
		RenderGroup.push_back(renderGroup());

		return &RenderGroup[RenderGroup.size() - 1];
	}
	void drawScreen()
	{
		for (int i = 0; i < RenderGroup.size(); i++)
		{
			RenderGroup[i].draw();
		}
	}
};

//������Ҫ������Ҫ�޸ĵ�Screen��Ȼ���ٽ��в���
class screens
{
	std::vector<screen> Screen;
public:
	std::vector<GLuint> VertexArrays;

	unsigned int NowEnableScreen = 0;

	//��Ⱦ
	void enableScreen(unsigned int ScreenID)
	{
		if (ScreenID < Screen.size())
		{
			glBindVertexArray(VertexArrays[ScreenID]);

			NowEnableScreen = ScreenID;

			return;
		}
		throw(1001);
	}
	void drawScreen()
	{
		Screen[NowEnableScreen].drawScreen();
	}
	//�޸�����
	unsigned int addScreen()
	{
		Screen.push_back(screen());
		VertexArrays.resize(Screen.size());

		glGenVertexArrays(1,&VertexArrays[Screen.size() - 1]);

		return Screen.size() - 1;
	}
	renderGroup* addRenderGroup()
	{
		return Screen[NowEnableScreen].addRenderGroup();
	}
};