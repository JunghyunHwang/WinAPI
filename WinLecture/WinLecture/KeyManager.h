#pragma once

namespace assort
{
    class App;

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