#include "App.h"

namespace assort
{
	App* App::mInstance = nullptr;

	HWND App::mHWnd = 0;
	HDC App::mHDC = 0;
	POINT App::mResolution = { 0, 0 };
	HBITMAP App::mHBit = 0;
	HDC App::mMemDC = 0;

	App::App()
		: mTimeManager()
		, mKeyManager()
		, mObject(0, 0, 100, 100)
	{
	}

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
		DeleteDC(mMemDC);
		DeleteObject(mHBit);
		ReleaseDC(mHWnd, mHDC);
		delete mInstance;
	}

	HWND App::GetMainHwnd()
	{
		return mHWnd;
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

		mObject.mPos.mX = mResolution.x / 2.0;
		mObject.mPos.mY = mResolution.y / 2.0;
	}

	void App::Run()
	{
		mTimeManager.update();
		mKeyManager.update();

		update();
		render();
	}

	void App::update()
	{
		const float objSpeed = mObject.mSpeed;

		if (mKeyManager.getKeyState(eKeyValue::Left) == eKeyState::Hold)
		{
			mObject.mPos.mX -= objSpeed * mTimeManager.getDT();
		}

		if (mKeyManager.getKeyState(eKeyValue::Right) == eKeyState::Hold)
		{
			mObject.mPos.mX += objSpeed * mTimeManager.getDT();
		}

		if (mKeyManager.getKeyState(eKeyValue::Up) == eKeyState::Hold)
		{
			mObject.mPos.mY -= objSpeed * mTimeManager.getDT();
		}

		if (mKeyManager.getKeyState(eKeyValue::Down) == eKeyState::Hold)
		{
			mObject.mPos.mY += objSpeed * mTimeManager.getDT();
		}
	}

	void App::render()
	{
		Rectangle(mMemDC, -1, -1, mResolution.x + 1, mResolution.y + 1);

		Rectangle(mMemDC
			, mObject.mPos.mX - mObject.mScale.mX / 2
			, mObject.mPos.mY - mObject.mScale.mY / 2
			, mObject.mPos.mX + mObject.mScale.mX / 2
			, mObject.mPos.mY + mObject.mScale.mY / 2);

		BitBlt(mHDC, 0, 0, mResolution.x, mResolution.y
			, mMemDC, 0, 0, SRCCOPY);
	}

	void App::objectSpeedUp()
	{
		if (mObject.mSpeed < 1200)
		{
			mObject.mSpeed += 50;
		}
	}

	int App::getObjectSpeed()
	{
		return mObject.mSpeed;
	}
}
