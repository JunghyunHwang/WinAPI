#include "App.h"
#include "Object.h"
#include "TimeManager.h"

namespace assort
{
	App* App::mInstance = nullptr;

	HWND App::mHWnd = 0;
	HDC App::mHDC = 0;
	POINT App::mResolution = { 0, 0 };
	HBIPMAP App::mHBit = 0;
	HDC App::mMemDC = 0;

	Object* App::mObject = nullptr;
	TimeManager* App::mTimeManager = nullptr;


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
		delete mTimeManager;

		DeleteDC(mMemDC);
		DeleteObject(mHBit);
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

		mHBit = CreateCompatibleBitmap(mHDC, mResolution.x, mResolution.y);
		mMemDC = CreateCompatibleDC(mHDC);
		DeleteObject(SelectObject(mMemDC, mHBit));

		mObject = new Object(mResolution.x / 2, mResolution.y / 2, 100, 100);
		mTimeManager = new TimeManager();
	}

	void App::Run()
	{
		mTimeManager->Update();

		update();
		render();
	}

	HWND App::GetMainHwnd()
	{
		return mHWnd;
	}

	void App::update()
	{
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			mObject->mPos.mX -= 200 * mTimeManager->GetDT();
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			mObject->mPos.mX += 200 * mTimeManager->GetDT();
		}
	}

	void App::render()
	{
		Rectangle(mMemDC, -1, -1, mResolution.x + 1, mResolution.y + 1);

		Rectangle(mMemDC
			, mObject->mPos.mX - mObject->mScale.mX / 2
			, mObject->mPos.mY - mObject->mScale.mY / 2
			, mObject->mPos.mX + mObject->mScale.mX / 2
			, mObject->mPos.mY + mObject->mScale.mY / 2);

		BitBlt(mHDC, 0, 0, mResolution.x, mResolution.y
			, mMemDC, 0, 0, SRCCOPY);
	}
}
