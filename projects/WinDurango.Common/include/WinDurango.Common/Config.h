/*
 * Created by DexrnZacAttack on 1/23/26 using zPc-i2.
 * WinDurango.Common::Config
*/
#pragma once
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>

namespace wd::common {
    class Config {
    public:
        Config() {}
        Config(std::string file, bool ReadOnly = false) {}

        /*
         * Operator Overloading
         * https://en.cppreference.com/w/cpp/language/operators.html
        */
        template<typename T>
        T& operator[](std::string node) {}
    };
}
