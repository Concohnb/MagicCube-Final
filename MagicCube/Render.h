#pragma once

#include "MagicCube.h"
#include <mutex>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class camera
{
	bool HasCameraChange = true;

	std::mutex MutexLock;

	glm::mat4 GobalTranslate = glm::translate(glm::mat4(), glm::vec3(0.0, 0.0, 0.0));
	glm::mat4 GobalRotate = glm::rotate_slow(glm::mat4(), 0.0f, glm::vec3(0.0f, 1.0f, 0.0f));

public:
	int Mob = -1;

	//��֧�ֶ��߳�
	glm::mat4 GobalProjection = glm::perspective(45.0f, (GLfloat)640 / (GLfloat)480, 0.1f, 500.0f);

	//֧�ֶ��߳�,��ȡȫ��ƽ��
	glm::mat4 readGobalTranslate()
	{
		MutexLock.lock();
	
		glm::mat4 ReadData = GobalTranslate;

		MutexLock.unlock();

		return ReadData;
	}
	//֧�ֶ��̣߳���ȡȫ����ת
	glm::mat4 readGobalRotate()
	{
		MutexLock.lock();

		glm::mat4 ReadData = GobalRotate;

		MutexLock.unlock();

		return ReadData;
	}
	//֧�ֶ��߳�,д��ȫ��ƽ��
	void writeGobalTranslate(glm::mat4 *InputData)
	{
		MutexLock.lock();

		GobalTranslate = *InputData;

		HasCameraChange = true;

		MutexLock.unlock();
	}
	//֧�ֶ��̣߳�д��ȫ����ת
	void writeGobalRotate(glm::mat4 *InputData)
	{
		MutexLock.lock();

		GobalRotate = *InputData;

		HasCameraChange = true;

		MutexLock.unlock();
	}
	bool hasCameraChange()
	{
		MutexLock.lock();

		bool HasCameraChange = camera::HasCameraChange;

		MutexLock.unlock();

		return HasCameraChange;
	}
};
extern camera Camera;

extern std::vector<GLuint> TextureList;