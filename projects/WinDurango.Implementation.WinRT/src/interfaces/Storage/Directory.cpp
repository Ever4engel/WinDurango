#include "WinDurango.Implementation.WinRT/Interfaces/Storage/Directory.h"

bool wd::impl::winrt::interfaces::storage::WinRTDirectory::open() {
    StorageFolder sf = ApplicationData::Current().LocalFolder();
    if (sf) {
        dir = &sf;
        return true;
    }
    return false;
}

wd::common::interfaces::storage::File* wd::impl::winrt::interfaces::storage::WinRTDirectory::CreateFile(std::filesystem::path path) {
    auto file = localFolder.CreateFileAsync(winrt::hstring(path.wstring()), winrt::Windows::Storage::CreationCollisionOption::FailIfExists).get();
    return nullptr;
}

wd::common::interfaces::storage::Directory* wd::impl::winrt::interfaces::storage::WinRTDirectory::CreateDirectory(std::filesystem::path path) {
    return nullptr;
}

std::filesystem::path wd::impl::winrt::interfaces::storage::WinRTDirectory::dirpath() {
    return path;
}
            
bool wd::impl::winrt::interfaces::storage::WinRTDirectory::rename(std::string) {
    return false;
}

bool wd::impl::winrt::interfaces::storage::WinRTDirectory::remove() {
    return false;
}

bool wd::impl::winrt::interfaces::storage::WinRTDirectory::move(std::filesystem::path path) {
    return false;
}

bool wd::impl::winrt::interfaces::storage::WinRTDirectory::copy(std::filesystem::path path) {
    return false;
}