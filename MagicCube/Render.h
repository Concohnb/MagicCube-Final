#pragma once

#include "RenderGroup.h"
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//����Shader����Ľṹ
typedef struct
{
	GLenum       type;
	const char*  filename;
	GLuint       shader;
} shaderInfo;
//����Shader�ĺ���
GLuint loadShaders(shaderInfo* shaders);

class shader
{
	unsigned int ShaderProgramID = 0;
public:
	shader(std::string ShaderName)
	{

		ShaderName = "GLSL\\" + ShaderName;

		std::string Vert = ShaderName;
		Vert.append(".vert");
		std::string Frag = ShaderName;
		Frag.append(".frag");

		shaderInfo  shaders[] = {
			{ GL_VERTEX_SHADER, Vert.c_str() },
			{ GL_FRAGMENT_SHADER, Frag.c_str() },
			{ GL_NONE, NULL } };

		ShaderProgramID = loadShaders(shaders);
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
		for (unsigned int i = 0; i < RenderGroup.size(); i++)
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
		}
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