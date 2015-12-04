#pragma once

#include "Render.h"

//��ɫ��������Ϣ
typedef void(*setShaderData)();
typedef void(*prepareRender)(GLuint ProgramID);

//һ��shader
struct shader
{
	prepareRender PrepareRender;
public:
	setShaderData SetShaderData;

	shader(int ProgramID, setShaderData SetShaderData, prepareRender PrepareRender,unsigned char DataSize)
	{
		shader::DataSize		= DataSize;
		shader::SetShaderData	= SetShaderData;
		shader::PrepareRender	= PrepareRender;
		shader::ProgramID		= ProgramID;
	}
	void prepareRender()
	{
		PrepareRender(ProgramID);
	}
	unsigned char DataSize;
	unsigned int  ProgramID;
};

extern std::vector<GLuint> UniformLocation;
extern std::vector<shader> Shader;
//����
void normail3DSet();
void normail3DPrepare(GLuint ProgramID);