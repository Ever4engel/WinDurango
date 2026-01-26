#pragma once
#include <istream>
#include <filesystem>
#include "WinDurango.Implementation.WinRT/WinDurangoWinRT.h"
#include "WinDurango.Common/Interfaces/Storage/File.h"

namespace wd::impl::winrt::interfaces::storage {
    class WDIMPL_API WinRTFile : public wd::common::interfaces::storage::File {
    public:
        WinRTFile(std::filesystem::path filepath) : path(filepath) {}

        virtual bool open() override;
        virtual bool create() override;
        virtual std::istream& read() override;
        virtual void operator<<(std::string data) override; // write
        virtual bool close() override;

        virtual std::filesystem::path filepath() override;
        
        virtual bool rename(std::string) override;
        virtual bool remove() override;
        virtual bool move(std::filesystem::path path) override;
        virtual bool copy(std::filesystem::path path) override;
    private:
        std::filesystem::path path;
    };
}