//
// Created by James Miller on 11/29/2024.
//

#include "MillerEngine.h"
#include <imgui.h>
#include <iostream>
#include <ostream>

#include "src/Windows/EngineSubWindows/Explorer.h"

#include "PracticeWindow.h"
#include "src/Windows/Capabilities.h"

void MillerEngine::startEngine()
{
    explorer->Open();
    millerIncLander->Open();
}


void MillerEngine::runEngine()
{
    // Start the engine
    MillerIncGui::Capabilities::AddDockSpace();

    // explorer->Draw();

    // Open the windows
    viewportWindow();
    outlinerWindow();
    inspectorWindow();
    sceneWindow();
    explorerWindow();
}

void MillerEngine::stopEngine()
{
    // Stop the engine
}

void MillerEngine::viewportWindow()
{
    // Render the viewport window
    ImGui::Begin("Viewport");

    ImGui::End();
}

void MillerEngine::outlinerWindow()
{
    // Render the outliner window
    ImGui::Begin("Outliner");

    ImGui::End();
}

void MillerEngine::inspectorWindow()
{
    // Render the inspector window
    ImGui::Begin("Inspector");

    ImGui::End();
}

void MillerEngine::sceneWindow()
{
    // Render the scene window
    ImGui::Begin("Scene");

    ImGui::End();
}

void MillerEngine::explorerWindow()
{
    explorer->Draw();
    millerIncLander->Draw();
}

