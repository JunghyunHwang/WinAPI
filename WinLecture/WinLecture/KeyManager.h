#pragma once

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
        enum
        {
            TOTAL_KEY_COUNT = static_cast<int>(eKeyValue::COUNT)
        };
        static int mVkArray[TOTAL_KEY_COUNT];
        KeyInfo mKeys[TOTAL_KEY_COUNT];
    };
}