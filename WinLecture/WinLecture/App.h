#pragma once

#include "Object.h"
#include "TimeManager.h"
#include "KeyManager.h"

namespace assort
{
	class App final
	{
		friend TimeManager;
	public:
		static App* GetInstance();
		static void Release();

		void Init(HWND hWnd, POINT resolution);
		void Run();

		static HWND GetMainHwnd();

	private:
		App();
		~App() = default;
		App(const App& other) = delete;
		App& operator=(const App& rhs) = delete;

		void update();
		void render();
		void objectSpeedUp();
		float getObjectSpeed() const;

	private:
		static App* mInstance;

		static HWND mHWnd;
		static POINT mResolution;
		static HDC mHDC;
		static HBITMAP mHBit;
		static HDC mMemDC;

		TimeManager mTimeManager;
		KeyManager mKeyManager;
		Object mObject;
	};
}
