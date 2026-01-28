//
// Created by DexrnZacAttack on 1/23/26 using zPc-i2.
//
#pragma once
#include <ctime>
#include "Interfaces/Storage/Directory.h"
#include "Config.h"
#include "Logging.h"
#include "exports.h"

namespace wd::common {
    class WD_API WinDurango {
    public:
        static std::shared_ptr<WinDurango> GetInstance();

        WinDurango() = default;

        void Init(std::shared_ptr<interfaces::storage::Directory> rootDir);
        bool inited();

        Config config;
        Logging log;

    private:
        bool _inited = false;
        std::shared_ptr<interfaces::storage::Directory> rootDir;
        std::shared_ptr<interfaces::storage::Directory> WinDurangoRoot;
    };
} // namespace wd::common

