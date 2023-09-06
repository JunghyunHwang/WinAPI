#include "ObjectManager.h"

namespace assort
{
	ObjectManager::ObjectManager()
	{
		mObjects.reserve(DEFAULT_OBJECT_COUNT);
	}

	ObjectManager::~ObjectManager()
	{
		for (auto obj : mObjects)
		{
			delete obj;
		}
	}

	ObjectManager* ObjectManager::GetInstance()
	{
		static ObjectManager instance;

		return &instance;
	}

	void ObjectManager::update()
	{
		for (auto obj : mObjects)
		{
			obj->update();
		}
	}

	void ObjectManager::addObject()
	{
		mObjects.push_back(new Rectangle());
	}
}
