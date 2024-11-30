//
// Created by jwmil on 11/30/2024.
//

#include "FileManager.h"

#include <iostream>

#include "CrossPlatformMacros.h"
#include <utility>

namespace MillerGui {
    FileManager::FileManager(std::filesystem::path path)
    {
        SetPath(std::move(path));
        thread = new std::thread();
    };

    FileManager::~FileManager()
    {
        End(); // Stop the file manager
        free(thread); // Free the path
        delete thread;
    }

    std::thread* FileManager::getNewFileThread()
    {
        return new std::thread(&FileManager::getFiles, this);
    }

    std::filesystem::path FileManager::GetPath()
    {
        return {path};
    }

    void FileManager::SetPath(std::filesystem::path path)
    {
        if (path == std::filesystem::path())
            throw std::invalid_argument("Path cannot be empty");
        if (!std::filesystem::exists(path))
            throw std::invalid_argument("Path does not exist");
        FileManager::path = std::move(path);
    }

    void FileManager::Restart()
    {
        End();
        Start();
    }

    void FileManager::Start()
    {
        running = true;
        thread = getNewFileThread();

    }

    void FileManager::End()
    {
        running = false;
    }

    /// <summary>
    ///     Get the files in the directory, use on a separate thread
    /// </summary>
    void FileManager::getFiles()
    {
        while (running){
            if (MDEBUG)
                std::cout << "Getting files in " << path << std::endl;
            for (const auto & entry : std::filesystem::directory_iterator(path))
            {
                files.emplace(entry.path());
            }
            if (MDEBUG)
                std::cout << "Files: " << files.size() << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }

    std::set<std::filesystem::path> FileManager::GetFiles()
    {
        return files;
    }




} // MillerGui