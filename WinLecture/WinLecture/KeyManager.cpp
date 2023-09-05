#include "KeyManager.h"

namespace assort
{
    KeyManager* KeyManager::mInstance = nullptr;

    KeyManager* KeyManager::GetInstance()
    {
        if (mInstance == nullptr)
        {
            mInstance = new KeyManager();
        }

        return mInstance;
    }

    void KeyManager::DeleteInstance()
    {
        delete mInstance;
    }
}