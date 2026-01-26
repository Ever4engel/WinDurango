#pragma once
#include "WinDurango.Implementation.WinRT/WinDurangoWinRT.h"
#include "WinDurango.Common/interfaces/Storage/Directory.h"

/*
 * I wonder if this is too confusing?
*/
namespace wd::impl::winrt::interfaces::storage {
    class WDIMPL_API WinRTDirectory : public wd::common::interfaces::storage::Directory {
    public:
        WinRTDirectory(std::filesystem::path dirpath) : path(dirpath) {}

        virtual bool open() override;
        virtual wd::common::interfaces::storage::File* CreateFile(std::filesystem::path path) override;
        virtual wd::common::interfaces::storage::Directory* CreateDirectory(std::filesystem::path path) override;

        virtual std::filesystem::path dirpath() override;
        
        virtual bool rename(std::string) override;
        virtual bool remove() override;
        virtual bool move(std::filesystem::path path) override;
        virtual bool copy(std::filesystem::path path) override;
    private:
        std::filesystem::path path;
    };
}