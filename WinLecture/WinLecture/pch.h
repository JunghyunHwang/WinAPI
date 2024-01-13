#pragma once
#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>
// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <vector>

namespace assort
{
    struct Vec4
    {
        float left;
        float top;
        float right;
        float bottom;
    };

    struct Size
    {
        uint32_t width;
        uint32_t height;
    };

    enum class eKeyState
    {
        None,
        Tap,
        Hold,
        Away
    };

    enum class eKeyValue
    {
        Left,
        Right,
        Up,
        Down,

        W,
        A,
        S,
        D,
        COUNT
    };

    struct KeyInfo
    {
        eKeyState state;
        bool bIsPressed;
    };
}
