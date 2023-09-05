#pragma once

#include "framework.h"

namespace assort
{
	class Object;
	class TimeManager;

	class App final
	{
	public:
		static App* GetInstance();
		static void Release();

		void Init(HWND hWnd, POINT resolution);
		void Run();

		static HWND GetMainHwnd();

	private:
		App() = default;
		~App() = default;
		App(const App& other) = delete;
		App& operator=(const App& rhs) = delete;

		void update();
		void render();

	private:
		static App* mInstance;
		static HWND mHWnd;
		static POINT mResolution;
		static HDC mHDC;
		static Object* mObject;
		static TimeManager* mTimeManager;
		static HBITMAP mHBit;
		static HDC mMemDC;
	};
}
