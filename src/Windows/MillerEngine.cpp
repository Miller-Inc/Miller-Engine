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
#include "Workers/Logger.h"

void MillerEngine::startEngine(std::string path)
{
    MillerEngine::path = path;
    explorer = new Explorer(path);

    // Start the engine
    explorer->Open();
    // millerIncLander->Open();
}


void MillerEngine::runEngine()
{
    // Start the engine
    MillerIncGui::Capabilities::AddDockSpaceMenuBar();

    // explorer->Draw();

    // Open the windows
    viewportWindow();
    outlinerWindow();
    inspectorWindow();
    sceneWindow();
    explorerWindow();
    // millerIncLander->Draw();
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
}

std::vector<std::string>* MillerEngine::argumentParser(int argc, char* argv[])
{
    auto* arguments = new std::vector<std::string>();
    if (argv == nullptr)
    {
        return arguments;
    }

    for (int i = 0; i < argc; i++)
    {

        // std::cout << argv[i] << std::endl;
        // arguments.push_back(argv[i]);
    }

    std::string argument;

    for (int i = 0; i < argc; i++)
    {
        std::cout << argv[i] << std::endl;

        if (*argv[i] == ' ' && !argument.empty())
        {
            arguments->push_back(argument); // Add the argument to the list
            argument = ""; // Reset the argument
        }
        else
        {
            argument += argv[i]; // Add the argument to the string
        }
    }
    return arguments;
}

enum class ArgumentType
{
    Unknown = -1,
    FileName = 0,
    Backend = 1,

};

std::string MillerEngine::setup(int argc, char* argv[])
{
    LOG("Miller Engine Started");
    LOG("All Rights Reserved");
    LOG("James Miller 2024");
    LOG("Version 0.0.1");

    auto argumentType = ArgumentType::Unknown;
    std::string fileName = "";

    if (argc > 1)
    {
        for (int i = 1; i < argc; i++) // Start from 1 to skip the program name
        {
            if (std::string(argv[i]) == "-f")
            {
                argumentType = ArgumentType::FileName;
            }
            else if (std::string(argv[i]) == "-b")
            {
                argumentType = ArgumentType::Backend;
            }
            else
            {
                if (argumentType == ArgumentType::FileName)
                {
                    LOG("Setting Filepath to: " << argv[i]);
                    fileName = argv[i];
                }
                else if (argumentType == ArgumentType::Backend)
                {
                    LOG("Backend Requested: " << argv[i]);
                }
                argumentType = ArgumentType::Unknown;
            }
        }
    }

    return fileName;
}

