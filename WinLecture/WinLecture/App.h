#pragma once

#include "framework.h"
#include "CObject.h"

namespace assort
{
	class CObject;

	class App
	{
	public:
		static App* GetInstance();
		static void Release();

		void Init(HWND hWnd, POINT resolution);
		void Run();

	private:
		App() = default;
		~App() = default;

		void update();
		void render();

	private:
		static App* mInstance;
		static HWND mHWnd;
		static POINT mResolution;
		static HDC mHDC;
		static CObject* mObject;
	};
}
