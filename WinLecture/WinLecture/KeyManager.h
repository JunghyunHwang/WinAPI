#pragma once
#include "framework.h"

namespace assort
{
    class App;

    class KeyManager final
    {
        friend App;
    public:
        KeyManager();
        ~KeyManager() = default;
        KeyManager(const KeyManager& other) = delete;
        KeyManager& operator=(const KeyManager& rhs) = delete;

    private:
        void update();
        eKeyState getKeyState(eKeyValue val) const;

    private:
        static int mVkArray[TOTAL_KEY_COUNT];
        KeyInfo mKeys[TOTAL_KEY_COUNT];
    };
}