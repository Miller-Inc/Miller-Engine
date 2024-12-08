//
// Created by James Miller on 11/29/2024.
//

#pragma once
#include <filesystem>

#include "SubWindowInterface.h"
#include "EngineSubWindows/Explorer.h"
#include "EngineSubWindows/MillerIncLander.h"

class MillerEngine {
public:
    void startEngine(std::string path);

    void runEngine();

    void stopEngine();

    void viewportWindow();

    void outlinerWindow();

    void inspectorWindow();

    void sceneWindow();

    void explorerWindow();

    static inline std::filesystem::path path = std::filesystem::current_path();

    static inline Explorer* explorer = new Explorer(path.string());

    static inline MillerIncLander* millerIncLander = new MillerIncLander();

    static std::vector<std::string>* argumentParser(int argc, char* argv[]);

    static std::string setup(int argc, char* argv[]);
};
