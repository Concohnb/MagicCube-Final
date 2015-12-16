
#include "Block.h"

blocks Blocks;

void stone(std::vector<GLfloat> *TodalData, int Addition, bool RenderTop, bool RenderDown, bool RenderLeft, bool RenderRight, bool RenderFront, bool RenderBack)
{
	if (RenderTop)
	{
		//�����
		TodalData->push_back(-1.0); TodalData->push_back(1.0); TodalData->push_back(-1.0);//����

		TodalData->push_back(0 / 32.0); TodalData->push_back(0 / 32.0);//����
																	   //�Һ���
		TodalData->push_back(1.0); TodalData->push_back(1.0); TodalData->push_back(-1.0);//����

		TodalData->push_back(1 / 32.0); TodalData->push_back(0 / 32.0);//����
																	   //��ǰ��
		TodalData->push_back(1.0); TodalData->push_back(1.0); TodalData->push_back(1.0);//����

		TodalData->push_back(1 / 32.0); TodalData->push_back(1 / 32.0);//����
																	   //��ǰ��
		TodalData->push_back(-1.0); TodalData->push_back(1.0); TodalData->push_back(1.0);//����

		TodalData->push_back(0 / 32.0); TodalData->push_back(1 / 32.0);//����
	}
	if (RenderDown)
	{
		TodalData->push_back(-1.0); TodalData->push_back(-1.0); TodalData->push_back(-1.0);//����

		TodalData->push_back(0 / 32.0); TodalData->push_back(0 / 32.0);//����
																	   
		TodalData->push_back(-1.0); TodalData->push_back(-1.0); TodalData->push_back(1.0);//����

		TodalData->push_back(1 / 32.0); TodalData->push_back(0 / 32.0);//����
																	   
		TodalData->push_back(1.0); TodalData->push_back(-1.0); TodalData->push_back(1.0);//����

		TodalData->push_back(1 / 32.0); TodalData->push_back(1 / 32.0);//����
																	   
		TodalData->push_back(1.0); TodalData->push_back(-1.0); TodalData->push_back(-1.0);//����

		TodalData->push_back(0 / 32.0); TodalData->push_back(1 / 32.0);//����
	}
	if (RenderLeft)
	{
		//�����
		TodalData->push_back(-1.0); TodalData->push_back(1.0); TodalData->push_back(-1.0);//����

		TodalData->push_back(0 / 32.0); TodalData->push_back(0 / 32.0);//����
																	   //�����
		TodalData->push_back(-1.0); TodalData->push_back(1.0); TodalData->push_back(1.0);//����

		TodalData->push_back(1 / 32.0); TodalData->push_back(0 / 32.0);//����
																	   //��ǰ��
		TodalData->push_back(-1.0); TodalData->push_back(-1.0); TodalData->push_back(1.0);//����

		TodalData->push_back(1 / 32.0); TodalData->push_back(1 / 32.0);//����
																	   //��ǰ��
		TodalData->push_back(-1.0); TodalData->push_back(-1.0); TodalData->push_back(-1.0);//����

		TodalData->push_back(0 / 32.0); TodalData->push_back(1 / 32.0);//����
	}
	if (RenderRight)
	{
		//�Һ���
		TodalData->push_back(1.0); TodalData->push_back(1.0); TodalData->push_back(-1.0);//����

		TodalData->push_back(0 / 32.0); TodalData->push_back(0 / 32.0);//����
																	   //�Һ���
		TodalData->push_back(1.0); TodalData->push_back(-1.0); TodalData->push_back(-1.0);//����

		TodalData->push_back(1 / 32.0); TodalData->push_back(0 / 32.0);//����
																	   //��ǰ��
		TodalData->push_back(1.0); TodalData->push_back(-1.0); TodalData->push_back(1.0);//����

		TodalData->push_back(1 / 32.0); TodalData->push_back(1 / 32.0);//����
																	   //��ǰ��
		TodalData->push_back(1.0); TodalData->push_back(1.0); TodalData->push_back(1.0);//����

		TodalData->push_back(0 / 32.0); TodalData->push_back(1 / 32.0);//����
	}
	if (RenderFront)
	{
		//��ǰ��
		TodalData->push_back(-1.0); TodalData->push_back(1.0); TodalData->push_back(1.0);//����

		TodalData->push_back(0 / 32.0); TodalData->push_back(0 / 32.0);//����
																	   //��ǰ��
		TodalData->push_back(1.0); TodalData->push_back(1.0); TodalData->push_back(1.0);//����

		TodalData->push_back(1 / 32.0); TodalData->push_back(0 / 32.0);//����
																	   //��ǰ��
		TodalData->push_back(1.0); TodalData->push_back(-1.0); TodalData->push_back(1.0);//����

		TodalData->push_back(1 / 32.0); TodalData->push_back(1 / 32.0);//����
																	   //��ǰ��
		TodalData->push_back(-1.0); TodalData->push_back(-1.0); TodalData->push_back(1.0);//����

		TodalData->push_back(0 / 32.0); TodalData->push_back(1 / 32.0);//����
	}
	if (RenderBack)
	{
		//�����
		TodalData->push_back(-1.0); TodalData->push_back(1.0); TodalData->push_back(-1.0);//����

		TodalData->push_back(0 / 32.0); TodalData->push_back(0 / 32.0);//����
																	   //�����
		TodalData->push_back(-1.0); TodalData->push_back(-1.0); TodalData->push_back(-1.0);//����

		TodalData->push_back(1 / 32.0); TodalData->push_back(0 / 32.0);//����
																	   //�Һ���
		TodalData->push_back(1.0); TodalData->push_back(-1.0); TodalData->push_back(-1.0);//����

		TodalData->push_back(1 / 32.0); TodalData->push_back(1 / 32.0);//����
																	   //�Һ���
		TodalData->push_back(1.0); TodalData->push_back(1.0); TodalData->push_back(-1.0);//����

		TodalData->push_back(0 / 32.0); TodalData->push_back(1 / 32.0);//����
	}
}

void initBlock()
{
	Blocks.addBlock("Stone", stone);
}