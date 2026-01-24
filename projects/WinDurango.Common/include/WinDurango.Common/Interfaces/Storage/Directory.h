//
// Created by DexrnZacAttack on 1/23/26 using zPc-i2.
//
#ifndef WINDURANGO_ABSTRACTSTORAGE_H
#define WINDURANGO_ABSTRACTSTORAGE_H

namespace wd::common::interfaces::storage {
    // TODO should we have separate project for interfaces?

    /** Interface for storage management, to be impl'd for uwp and crossplat */
    class Directory {
    public:
        Directory(std::filesystem::path root); // todo impl

        virtual void CreateFile(std::filesystem::path path) = 0; // todo maybe return stream type, todo can we use this in uwp context??? I forgor
        virtual void CreateDirectory(std::filesystem::path path) = 0;

        std::filesystem::path _root;
    };
} // wd::common::interfaces::storage

#endif // WINDURANGO_ABSTRACTSTORAGE_H