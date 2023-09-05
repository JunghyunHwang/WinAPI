#pragma once

namespace assort
{
    class KeyManager final
    {
    public:
        static KeyManager* GetInstance();
        static void DeleteInstance();

    private:
        KeyManager() = default;
        ~KeyManager() = default;
        KeyManager(const KeyManager& other) = delete;
        KeyManager& operator=(const KeyManager& rhs) = delete;

    private:
        static KeyManager* mInstance;
    };
}