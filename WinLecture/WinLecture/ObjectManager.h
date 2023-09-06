#pragma once

#include "framework.h"
#include "Object.h"

namespace assort
{
	class App;

	class ObjectManager final
	{
		friend App;
	public:
		ObjectManager* GetInstance();

	private:
		void update();
		void render();
		void addObject();

	private:
		ObjectManager();
		~ObjectManager();

	private:
		std::vector<Object*> mObjects;
	};
}
