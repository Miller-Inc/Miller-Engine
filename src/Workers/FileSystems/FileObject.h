//
// Created by James  on 12Miller/3/2024.
//

#pragma once
#include <string>
#include <vector>

namespace MillerGui
{

    enum class FileType
    {
        File,
        Directory,
        Unknown
    };

    struct FileObject
    {
        std::filesystem::path name;
        std::filesystem::path path;
        std::filesystem::path extension;
        // uint64_t size;
        MillerGui::FileType type;
        std::vector<FileObject> children;
        bool included;
    };
} // MillerGui
