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
    void startEngine();

    void runEngine();

    void stopEngine();

    void viewportWindow();

    void outlinerWindow();

    void inspectorWindow();

    void sceneWindow();

    void explorerWindow();

    static inline std::filesystem::path path = std::filesystem::current_path();

    static inline Explorer* explorer = new Explorer();

    static inline MillerIncLander* millerIncLander = new MillerIncLander();

};
