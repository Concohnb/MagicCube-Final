#pragma once

#include "Render.h"

//��ɫ��������Ϣ
typedef void(*useShader)(GLuint ProgramID);

//һ��shader
class shader
{
	useShader UseShader;
public:
	unsigned int  ProgramID;
	unsigned char DataSize;

	shader(int ProgramID, useShader UseShader,unsigned char DataSize)
	{
		shader::DataSize		= DataSize;
		shader::UseShader		= UseShader;
		shader::ProgramID		= ProgramID;
	}
	void useShader()
	{
		UseShader(ProgramID);
	}
};

extern std::vector<GLuint> UniformLocation;
extern std::vector<shader> Shader;
//����
void normail3DUse(GLuint ProgramID);