#include "interfaces/Storage/File.h"

namespace wd::impl::winrt::interfaces::storage {
    bool WinRTFile::open() {
        return false;
    }

    bool WinRTFile::create() {
        return false;
    }

    /*
     * From Stack Overflow
     * Why did this take me 4 hours to figure out??
    */
    struct MyIstream : std::streambuf {
    public:
        int_type underflow() override {
            return traits_type::eof();
        }
    };

    std::istream& WinRTFile::read() {
        MyIstream nullp;
        std::istream np(&nullp);
        return np;
    }

    void WinRTFile::operator<<(std::string data) {
        
    }
    
    bool WinRTFile::close() {
        return false;
    }

    std::filesystem::path WinRTFile::filepath() {
        return path;
    }

    bool WinRTFile::rename(std::string) {
        return false;
    }

    bool WinRTFile::remove() {
        return false;
    }

    bool WinRTFile::move(std::filesystem::path path) {
        return false;
    }

    bool WinRTFile::copy(std::filesystem::path path) {
        return false;
    }
}