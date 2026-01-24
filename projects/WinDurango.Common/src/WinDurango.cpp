//
// Created by DexrnZacAttack on 1/23/26 using zPc-i2.
//
#include "WinDurango.Common/WinDurango.h"

namespace wd::common {
    WinDurango *WinDurango::GetInstance() {
        static WinDurango Instance = WinDurango();

        return &Instance;
    }

    WinDurango::WinDurango() {
        this->_config = Config();
    }
}
