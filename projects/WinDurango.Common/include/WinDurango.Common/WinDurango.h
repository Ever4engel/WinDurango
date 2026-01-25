//
// Created by DexrnZacAttack on 1/23/26 using zPc-i2.
//
#pragma once

#include "Config.h"
#include "exports.h"

namespace wd::common
{
  class WD_API WinDurango
  {
    public:
      static WinDurango *GetInstance();

      WinDurango() = default;

      void Init();

      Config Config;

    private:
      bool _inited = false;
  };
} // namespace wd::common

