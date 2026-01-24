//
// Created by DexrnZacAttack on 1/23/26 using zPc-i2.
//
#ifndef WINDURANGO_COMMON_H
#define WINDURANGO_COMMON_H

#include "WinDurango.Common/Config.h"

namespace wd::common {
    class WinDurango {
    public:
        static WinDurango *GetInstance();

        WinDurango();

		Config &GetConfig();
	private:
		Config _config;
    };
}

#endif // WINDURANGO_COMMON_H