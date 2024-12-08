//
// Created by jwmil on 11/30/2024.
//

#include "FileManager.h"

#include <iostream>

#include "CrossPlatformMacros.h"
#include <utility>

#include "Workers/Logger.h"

namespace MillerGui {
    FileManager::FileManager(std::filesystem::path path)
    {
        SetPath(std::move(path));
        thread = new std::thread();
    };

    FileManager::~FileManager()
    {
        End(); // Stop the file manager
        // free(thread); // Free the path
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
        LOG("Starting file manager thread");
        while (running){
            lock = true;
            fileLayout = getFileObject(path);
            lock = false;
            std::this_thread::sleep_for(std::chrono::seconds(5));
        }
    }

    std::set<std::filesystem::path> FileManager::GetFiles()
    {
        return files;
    }

    FileObject FileManager::getFileObject(std::filesystem::path p) {

        FileObject obj;

        try {
            if (!hasReadPermission(p)) {
                LOG("No read permission for file: " << p);
                return {};
            }
            obj.name = p.filename();
            obj.extension = p.extension();
            obj.path = p;
            obj.included = true;
            obj.hasPermission = true;

            if (is_directory(p)) {
                obj.type = FileType::Directory;

                try
                {
                    for (const auto& entry : std::filesystem::directory_iterator(p)) {
                        if (hasReadPermission(entry))
                        {
                            obj.children.emplace_back(getFileObject(entry.path()));
                        }
                    }
                } catch (std::filesystem::filesystem_error& e) {
                    LOG_ERROR("Filesystem error: " << e.what());
                }

            } else {
                obj.type = FileType::File;
            }


            return obj;
        } catch (const std::filesystem::filesystem_error& e) {
            LOG_ERROR("Filesystem error: " << e.what());
            return obj;
        } catch (const std::exception& e) {
            LOG_ERROR("Error: " << e.what());
            return obj;
        }
    }

    FileObject FileManager::GetFileLayout() const
    {
        return fileLayout;
    }

    bool FileManager::hasReadPermission(const std::filesystem::path& path) {
        if (isExcluded(path))
        {
            return false;
        }
        std::filesystem::perms permissions = std::filesystem::status(path).permissions();
        return (permissions & std::filesystem::perms::owner_read) != std::filesystem::perms::none &&
               (permissions & std::filesystem::perms::group_read) != std::filesystem::perms::none &&
               (permissions & std::filesystem::perms::others_read) != std::filesystem::perms::none;
    }

    bool FileManager::isExcluded(const std::filesystem::path& path)
    {
        if (path.filename() == ".git")
            return true;
        if (path.filename() == ".vscode")
            return true;
        if (path.filename() == "System Volume Information")
        {
            return true;
        }
        if (path.filename() == "$RECYCLE.BIN")
        {
            return true;
        }
        if (path.filename() == "AppData")
        {
            return true;
        }
        if (path.filename() == "Windows")
        {
            return true;
        }
        if (path.filename() == "Program Files")
        {
            return true;
        }
        if (path.filename() == "Program Files (x86)")
        {
            return true;
        }
        if (path.filename() == "ProgramData")
        {
            return true;
        }
        if (path.filename() == "Windows.old")
        {
            return true;
        }
        if (path.filename() == "Users")
        {
            return true;
        }
        if (path.filename() == "Recovery")
        {
            return true;
        }
        if (path.filename() == "PerfLogs")
        {
            return true;
        }
        if (path.filename() == "OneDrive")
        {
            return true;
        }
        if (path.filename() == "Intel")
        {
            return true;
        }


        return false;
    }

    bool FileManager::Lock() const {
        return lock;
    }

} // MillerGui