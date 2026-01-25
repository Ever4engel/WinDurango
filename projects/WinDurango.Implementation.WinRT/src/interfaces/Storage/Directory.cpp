#include "interfaces/Storage/Directory.h"

namespace wd::impl::winrt::interfaces::storage {
    bool WinRTDirectory::open() {
        return false;
    }

    wd::common::interfaces::storage::File* WinRTDirectory::CreateFile(std::filesystem::path path) {
        return nullptr;
    }

    wd::common::interfaces::storage::Directory* WinRTDirectory::CreateDirectory(std::filesystem::path path) {
        return nullptr;
    }

    std::filesystem::path WinRTDirectory::dirpath() {
        return path;
    }
            
    bool WinRTDirectory::rename(std::string) {
        return false;
    }

    bool WinRTDirectory::remove() {
        return false;
    }

    bool WinRTDirectory::move(std::filesystem::path path) {
        return false;
    }

    bool WinRTDirectory::copy(std::filesystem::path path) {
        return false;
    }
}