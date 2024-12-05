//
// Created by James Miller on 11/29/2024.
//


// Generated with ImRAD 0.7
// visit https://github.com/tpecholt/imrad

#pragma once
#include <string>

#include "Windows/SubWindowInterface.h"
#include "Workers/FileSystems/FileManager.h"

class Explorer : public MillerGui::SubWindowInterface
{
public:
    Explorer();
    ~Explorer() override;

    /// @begin interface
    void Open() override;
    void Close() override;
    void Draw() override;

    std::string* input = new std::string();


    /// @end interface

private:
    /// @begin impl
    bool isOpen = true;
    MillerGui::FileManager* fileManager;

    static void createFileTree(const MillerGui::FileObject& fileLayout);

    void OpenPath(const std::string& path) const;

    /// @end impl
};
