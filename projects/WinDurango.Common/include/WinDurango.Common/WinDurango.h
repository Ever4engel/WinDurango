//
// Created by DexrnZacAttack on 1/23/26 using zPc-i2.
//
#pragma once

#ifdef WD_API_EXPORTS
  #define WD_API __declspec(dllexport)
#else
  #define WD_API __declspec(dllimport)
#endif

#include "Config.h"

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

