#include "App.h"

namespace assort
{
	App* App::mInstance = nullptr;
	HWND App::mHWnd = 0;
	HDC App::mHDC = 0;
	POINT App::mResolution = { 0, 0 };
	CObject* App::mObject = nullptr;

	App* App::GetInstance()
	{
		if (mInstance == nullptr)
		{
			mInstance = new App();
		}

		return mInstance;
	}

	void App::Release()
	{
		delete mObject;
		ReleaseDC(mHWnd, mHDC);
		delete mInstance;
	}

	void App::Init(HWND hWnd, POINT resolution)
	{
		mHWnd = hWnd;
		mResolution = resolution;
		mHDC = GetDC(mHWnd);

		RECT rt = { 0, 0, resolution.x, resolution.y };

		AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
		SetWindowPos(mHWnd, nullptr, 200, 200, rt.right - rt.left, rt.bottom - rt.top, 0);

		// Draw square
		mObject = new CObject(mResolution.x / 2, mResolution.y / 2, 100, 100);
	}

	void App::Run()
	{
		update();
		render();
	}

	void App::update()
	{
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			mObject->mPos.x += -1;
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			mObject->mPos.x += 1;
		}
	}

	void App::render()
	{
		Rectangle(mHDC
			, mObject->mPos.x - mObject->mScale.x / 2
			, mObject->mPos.y - mObject->mScale.y / 2
			, mObject->mPos.x + mObject->mScale.x / 2
			, mObject->mPos.y + mObject->mScale.y / 2);
	}
}

