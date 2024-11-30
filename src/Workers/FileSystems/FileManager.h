//
// Created by James Miller on 11/30/2024.
//

#pragma once

#include <cstdio>
#include <filesystem>
#include <map>
#include <set>
#include <thread>
#include <utility>

namespace MillerGui {

class FileManager {
public:
    void Start();

    void Restart(); // Restart the file manager

    void SetPath(std::filesystem::path path);

    std::filesystem::path GetPath();

    std::set<std::filesystem::path> GetFiles();

    void End();

    explicit FileManager(std::filesystem::path path); // Constructor

    ~FileManager();

private:

    std::thread* thread;

    std::filesystem::path path;

    bool running = true;

    std::thread* getNewFileThread();

    std::set<std::filesystem::path> files;

    void getFiles();

};

} // MillerGui

