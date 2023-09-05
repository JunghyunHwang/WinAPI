#include "KeyManager.h"
#include "framework.h"

namespace assort
{
    int KeyManager::mVkArray[] = { 
        VK_LEFT,
        VK_RIGHT,
        VK_UP,
        VK_DOWN,
        'W',
        'A',
        'S',
        'D'
    };

    KeyManager::KeyManager()
    {
        for (int i = 0; i < TOTAL_KEY_COUNT; ++i)
        {
            mKeys[i].state = eKeyState::None;
            mKeys[i].bIsPressed = false;
        }
    }

    eKeyState KeyManager::getKeyState(eKeyValue val) const
    {
        return mKeys[static_cast<int>(val)].state;
    }

    void KeyManager::update()
    {
        HWND hWnd = GetFocus();

        if (hWnd != nullptr)
        {
            for (int i = 0; i < TOTAL_KEY_COUNT; ++i)
            {
                if (GetAsyncKeyState(mVkArray[i]) & 0x8000)
                {
                    if (mKeys[i].bIsPressed)
                    {
                        mKeys[i].state = eKeyState::Hold;
                    }
                    else
                    {
                        mKeys[i].state = eKeyState::Tap;
                    }

                    mKeys[i].bIsPressed = true;
                }
                else
                {
                    if (mKeys[i].bIsPressed)
                    {
                        mKeys[i].state = eKeyState::Away;
                    }
                    else
                    {
                        mKeys[i].state = eKeyState::None;
                    }

                    mKeys[i].bIsPressed = false;
                }
            }
        }
        else
        {
            for (int i = 0; i < TOTAL_KEY_COUNT; ++i)
            {
                mKeys[i].bIsPressed = false;

                if (mKeys[i].state == eKeyState::Hold || mKeys[i].state == eKeyState::Tap)
                {
                    mKeys[i].state = eKeyState::Away;
                }
                else if (mKeys[i].state == eKeyState::Away)
                {
                    mKeys[i].state = eKeyState::None;
                }
            }
        }
    }
}