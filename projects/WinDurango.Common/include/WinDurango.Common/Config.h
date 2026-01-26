/*
 * Created by DexrnZacAttack on 1/23/26 using zPc-i2.
 * WinDurango.Common::Config
*/
#pragma once
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>
#include "Interfaces/Storage/File.h"

/*
 * TODO: Make it to write back
*/
namespace wd::common {
    class Config {
    public:
        Config() : pFile(nullptr), RO(false) {}
        Config(std::shared_ptr<interfaces::storage::File> file, bool ReadOnly = false) : pFile(file), RO(ReadOnly) {}

        bool parse();

        /*
         * Operator Overloading
         * https://en.cppreference.com/w/cpp/language/operators.html
        */
        template<typename T>
        T& operator[](std::string node);

        template<typename T>
        bool set(std::string node, T type);
    private:
        std::shared_ptr<interfaces::storage::File> pFile;
        bool RO;
        nlohmann::json data;
    };
}
