
#include "Block.h"

blocks Blocks;

void stone(renderGroup* RenderGroup, int Addition, bool RenderTop, bool RenderDown, bool RenderLeft, bool RenderRight, bool RenderFront, bool RenderBack, float X, float Y, float Z)
{
	if (RenderTop)
	{
		//�����
		RenderGroup->RenderData.push_back(-0.5f + X); RenderGroup->RenderData.push_back(0.5f + Y); RenderGroup->RenderData.push_back(-0.5f + Z);//����

		RenderGroup->RenderData.push_back(0 / 32.0); RenderGroup->RenderData.push_back(0 / 32.0);//����
																								 //�Һ���
		RenderGroup->RenderData.push_back(0.5f + X); RenderGroup->RenderData.push_back(0.5f + Y); RenderGroup->RenderData.push_back(-0.5f + Z);//����

		RenderGroup->RenderData.push_back(1 / 32.0); RenderGroup->RenderData.push_back(0 / 32.0);//����
																								 //��ǰ��
		RenderGroup->RenderData.push_back(0.5f + X); RenderGroup->RenderData.push_back(0.5f + Y); RenderGroup->RenderData.push_back(0.5f + Z);//����

		RenderGroup->RenderData.push_back(1 / 32.0); RenderGroup->RenderData.push_back(1 / 32.0);//����
																								 //��ǰ��
		RenderGroup->RenderData.push_back(-0.5f + X); RenderGroup->RenderData.push_back(0.5f + Y); RenderGroup->RenderData.push_back(0.5f + Z);//����

		RenderGroup->RenderData.push_back(0 / 32.0); RenderGroup->RenderData.push_back(1 / 32.0);//����
	}
	if (RenderDown)
	{
		RenderGroup->RenderData.push_back(-0.5f + X); RenderGroup->RenderData.push_back(-0.5f + Y); RenderGroup->RenderData.push_back(-0.5f + Z);//����

		RenderGroup->RenderData.push_back(0 / 32.0); RenderGroup->RenderData.push_back(0 / 32.0);//����

		RenderGroup->RenderData.push_back(-0.5f + X); RenderGroup->RenderData.push_back(-0.5f + Y); RenderGroup->RenderData.push_back(0.5f + Z);//����

		RenderGroup->RenderData.push_back(1 / 32.0); RenderGroup->RenderData.push_back(0 / 32.0);//����

		RenderGroup->RenderData.push_back(0.5f + X); RenderGroup->RenderData.push_back(-0.5f + Y); RenderGroup->RenderData.push_back(0.5f + Z);//����

		RenderGroup->RenderData.push_back(1 / 32.0); RenderGroup->RenderData.push_back(1 / 32.0);//����

		RenderGroup->RenderData.push_back(0.5f + X); RenderGroup->RenderData.push_back(-0.5f + Y); RenderGroup->RenderData.push_back(-0.5f + Z);//����

		RenderGroup->RenderData.push_back(0 / 32.0); RenderGroup->RenderData.push_back(1 / 32.0);//����
	}
	if (RenderLeft)
	{
		//�����
		RenderGroup->RenderData.push_back(-0.5f + X); RenderGroup->RenderData.push_back(0.5f + Y); RenderGroup->RenderData.push_back(-0.5f + Z);//����

		RenderGroup->RenderData.push_back(0 / 32.0); RenderGroup->RenderData.push_back(0 / 32.0);//����
																								 //�����
		RenderGroup->RenderData.push_back(-0.5f + X); RenderGroup->RenderData.push_back(0.5f + Y); RenderGroup->RenderData.push_back(0.5f + Z);//����

		RenderGroup->RenderData.push_back(1 / 32.0); RenderGroup->RenderData.push_back(0 / 32.0);//����
																								 //��ǰ��
		RenderGroup->RenderData.push_back(-0.5f + X); RenderGroup->RenderData.push_back(-0.5f + Y); RenderGroup->RenderData.push_back(0.5f + Z);//����

		RenderGroup->RenderData.push_back(1 / 32.0); RenderGroup->RenderData.push_back(1 / 32.0);//����
																								 //��ǰ��
		RenderGroup->RenderData.push_back(-0.5f + X); RenderGroup->RenderData.push_back(-0.5f + Y); RenderGroup->RenderData.push_back(-0.5f + Z);//����

		RenderGroup->RenderData.push_back(0 / 32.0); RenderGroup->RenderData.push_back(1 / 32.0);//����
	}
	if (RenderRight)
	{
		//�Һ���
		RenderGroup->RenderData.push_back(0.5f + X); RenderGroup->RenderData.push_back(0.5f + Y); RenderGroup->RenderData.push_back(-0.5f + Z);//����

		RenderGroup->RenderData.push_back(0 / 32.0); RenderGroup->RenderData.push_back(0 / 32.0);//����
																								 //�Һ���
		RenderGroup->RenderData.push_back(0.5f + X); RenderGroup->RenderData.push_back(-0.5f + Y); RenderGroup->RenderData.push_back(-0.5f + Z);//����

		RenderGroup->RenderData.push_back(1 / 32.0); RenderGroup->RenderData.push_back(0 / 32.0);//����
																								 //��ǰ��
		RenderGroup->RenderData.push_back(0.5f + X); RenderGroup->RenderData.push_back(-0.5f + Y); RenderGroup->RenderData.push_back(0.5f + Z);//����

		RenderGroup->RenderData.push_back(1 / 32.0); RenderGroup->RenderData.push_back(1 / 32.0);//����
																								 //��ǰ��
		RenderGroup->RenderData.push_back(0.5f + X); RenderGroup->RenderData.push_back(0.5f + Y); RenderGroup->RenderData.push_back(0.5f + Z);//����

		RenderGroup->RenderData.push_back(0 / 32.0); RenderGroup->RenderData.push_back(1 / 32.0);//����
	}
	if (RenderFront)
	{
		//��ǰ��
		RenderGroup->RenderData.push_back(-0.5f + X); RenderGroup->RenderData.push_back(0.5f + Y); RenderGroup->RenderData.push_back(0.5f + Z);//����

		RenderGroup->RenderData.push_back(0 / 32.0); RenderGroup->RenderData.push_back(0 / 32.0);//����
																								 //��ǰ��
		RenderGroup->RenderData.push_back(0.5f + X); RenderGroup->RenderData.push_back(0.5f + Y); RenderGroup->RenderData.push_back(0.5f + Z);//����

		RenderGroup->RenderData.push_back(1 / 32.0); RenderGroup->RenderData.push_back(0 / 32.0);//����
																								 //��ǰ��
		RenderGroup->RenderData.push_back(0.5f + X); RenderGroup->RenderData.push_back(-0.5f + Y); RenderGroup->RenderData.push_back(0.5f + Z);//����

		RenderGroup->RenderData.push_back(1 / 32.0); RenderGroup->RenderData.push_back(1 / 32.0);//����
																								 //��ǰ��
		RenderGroup->RenderData.push_back(-0.5f + X); RenderGroup->RenderData.push_back(-0.5f + Y); RenderGroup->RenderData.push_back(0.5f + Z);//����

		RenderGroup->RenderData.push_back(0 / 32.0); RenderGroup->RenderData.push_back(1 / 32.0);//����
	}
	if (RenderBack)
	{
		//�����
		RenderGroup->RenderData.push_back(-0.5f + X); RenderGroup->RenderData.push_back(0.5f + Y); RenderGroup->RenderData.push_back(-0.5f + Z);//����

		RenderGroup->RenderData.push_back(0 / 32.0); RenderGroup->RenderData.push_back(0 / 32.0);//����
																								 //�����
		RenderGroup->RenderData.push_back(-0.5f + X); RenderGroup->RenderData.push_back(-0.5f + Y); RenderGroup->RenderData.push_back(-0.5f + Z);//����

		RenderGroup->RenderData.push_back(1 / 32.0); RenderGroup->RenderData.push_back(0 / 32.0);//����
																								 //�Һ���
		RenderGroup->RenderData.push_back(0.5f + X); RenderGroup->RenderData.push_back(-0.5f + Y); RenderGroup->RenderData.push_back(-0.5f + Z);//����

		RenderGroup->RenderData.push_back(1 / 32.0); RenderGroup->RenderData.push_back(1 / 32.0);//����
																								 //�Һ���
		RenderGroup->RenderData.push_back(0.5f + X); RenderGroup->RenderData.push_back(0.5f + Y); RenderGroup->RenderData.push_back(-0.5f + Z);//����

		RenderGroup->RenderData.push_back(0 / 32.0); RenderGroup->RenderData.push_back(1 / 32.0);//����
	}
}

void initBlock()
{
	Blocks.addBlock("Stone", stone);
}