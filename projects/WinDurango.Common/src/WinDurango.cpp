//
// Created by DexrnZacAttack on 1/23/26 using zPc-i2.
//
#include "WinDurango.Common/WinDurango.h"

namespace wd::common
{
    WinDurango *WinDurango::GetInstance()
    {
        static WinDurango Instance = WinDurango(); // if we don't declare it in src, it will make multiple instances per
                                                   // header import in different libs afaik
        if (!Instance._inited)
            Instance.Init(); // lazy

        return &Instance;
    }

    void WinDurango::Init()
    {
        // todo load config

        this->_inited = true;
    }
} // namespace wd::common
