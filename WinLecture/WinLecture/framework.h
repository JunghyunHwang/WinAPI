// header.h : include file for standard system include files,
// or project specific include files
//

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

constexpr int TOTAL_KEY_COUNT = static_cast<int>(eKeyValue::COUNT);
constexpr int DEFAULT_OBJECT_COUNT = 64;
