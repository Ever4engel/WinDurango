//
// Created by DexrnZacAttack on 1/23/26 using zPc-i2.
//
#ifndef WINDURANGO_ABSTRACTSTORAGE_H
#define WINDURANGO_ABSTRACTSTORAGE_H

namespace wd::winrt {
    /** Interface for storage management, to be impl'd for uwp and crossplat */
    class AbstractStorage {
    public:
        // todo can't make these static, what to do?
        virtual void CreateFile(std::filesystem::path path) = 0; // todo maybe return stream type, todo can we use this in uwp context??? I forgor
        virtual void CreateDirectory(std::filesystem::path path) = 0;
    };
} // wd::winrt

#endif // WINDURANGO_ABSTRACTSTORAGE_H