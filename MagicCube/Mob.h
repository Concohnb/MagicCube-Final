#pragma once

#include "MagicCube.h"

class mob;
//���������Ϣ
typedef void(*refreshMob)(mob*);
typedef void(*renderMob)(mob*);

//���������Ϣ����Ⱦ���ƶ��ȣ�
struct mobType
{
	refreshMob RefreshMob;
	renderMob  RenderMob;
};

//��������
struct location
{
	float X;
	float Y;
	float Z;

	double XRot;
	double YRot;
};

//����һ������
class mob
{
	friend class mobs;

	refreshMob RefreshMob;
	renderMob  RenderMob;
public:
	location   MobLocation;

	double Speed;
	double LastMoveTime=glfwGetTime();

	//��ʼ������
	mob(refreshMob RefreshMob,renderMob  RenderMob)
	{
		mob::RefreshMob = RefreshMob;
		mob::RenderMob  = RenderMob;

		MobLocation.X = 0;
		MobLocation.Y = 0;
		MobLocation.Z = 0;

		MobLocation.XRot = 0;
		MobLocation.YRot = 0;

		Speed = 1;
	}
};

class mobs
{

public:
	std::vector<mob> Mob;

	//ˢ����������λ��
	void refreshMobs()
	{
		for (unsigned int i = 0; i < Mob.size(); i++)
		{
			Mob[i].RefreshMob(&Mob[i]);
		}
	}
	//�������
	mob* addMob(mobType ModType)
	{
		Mob.push_back(mob(ModType.RefreshMob, ModType.RenderMob));
		return &Mob[Mob.size() - 1];
	}
};

extern mobs Mob;
extern std::vector<mobType> MobType;