//
// Created by James Miller on 11/29/2024.
//

#include "Explorer.h"
#include <imgui.h>
#include <iostream>
#include <csignal>

Explorer::Explorer()
{
    currentPath = new std::string(std::filesystem::current_path().string());
    isOpen = false;
    fileManager = new MillerGui::FileManager(std::filesystem::path(*currentPath));
}

Explorer::Explorer(const std::string* path)
{
    currentPath = new std::string(*path);
    isOpen = false;
    fileManager = new MillerGui::FileManager(std::filesystem::path(*currentPath));
}

Explorer::Explorer(const std::string& string)
{
    currentPath = new std::string(string);
    isOpen = false;
    fileManager = new MillerGui::FileManager(std::filesystem::path(*currentPath));
}

Explorer::~Explorer()= default;



void Explorer::Open()
{
    isOpen = true;
    fileManager->Start();
}

void Explorer::Close()
{
    isOpen = false;
    fileManager->End();
}

void Explorer::Draw()
{
    ImGui::SetNextWindowSize({ 640, 480 }, ImGuiCond_FirstUseEver);
    if (isOpen && ImGui::Begin("Explorer", &isOpen))
    {
        // ImGui::BeginChild("child1##Child", { 620, 430 }, ImGuiChildFlags_AlwaysUseWindowPadding, ImGuiWindowFlags_NoSavedSettings);
        // {
        ImGui::Text("Search");
        ImGui::SameLine(0, 1 * ImGui::GetStyle().ItemSpacing.x);
        ImGui::SetNextItemWidth(500);
        char inputText[4096] = "";
        if (ImGui::InputText("###ExplorerTextInput", inputText, IM_ARRAYSIZE(inputText),
            ImGuiInputTextFlags_EnterReturnsTrue))
        {
            if (ImGui::IsKeyPressed(ImGuiKey_Enter))
            {
                OpenPath(inputText);
            }
            if (ImGui::IsKeyPressed(ImGuiKey_Tab))
            {
                ImGui::SetKeyboardFocusHere();
            }

        }




        input = new std::string(inputText);

        // ImGui::SameLine( 10, 1 * ImGui::GetStyle().ItemSpacing.x);
        ImGui::Button("Go to Path###ExplorerGoToPath", { 100, 20});

        if (ImGui::IsItemHovered())
            ImGui::SetTooltip("Go to path");
        if (ImGui::IsItemClicked())
            OpenPath(*input);

        if (ImGui::IsItemActive())
            if (ImGui::IsItemHovered(ImGuiHoveredFlags_DelayShort))
                ImGui::SetTooltip("Search for file or folder");

        ImGui::SameLine(0, 1 * ImGui::GetStyle().ItemSpacing.x);
        ImGui::Button("Refresh###ExplorerRefresh", { 100, 20});
        if (ImGui::IsItemHovered())
            ImGui::SetTooltip("Refresh");

        ImGui::SameLine(0, 1 * ImGui::GetStyle().ItemSpacing.x);
        ImGui::Text(currentPath->c_str(), ImGui::GetStyle().ItemSpacing.x);

        MillerGui::FileObject fileLayout = fileManager->GetFileLayout();


        createFileTree(fileLayout, fileManager);

        // ImGui::SetNextItemOpen(true, ImGuiCond_Appearing);
        // if (ImGui::TreeNodeEx("Folder", ImGuiTreeNodeFlags_None))
        {
            // ImGui::TreePop();
        }
        // ImGui::EndChild();
        // }
        ImGui::End();
    }
}

void Explorer::createFileTree(const MillerGui::FileObject& fileHead, MillerGui::FileManager* fileManager)
{
    const MillerGui::FileObject* fileLayout = nullptr;
    if (fileManager->Lock())
    {

    }
    else
    {
        copyFileObject = &fileHead;
    }


    fileLayout = &fileHead;
    for (auto & file : fileLayout->children)
    {
        if (MillerGui::FileManager::isExcluded(file.path))
            continue;

        if (file.hasPermission == false)
            continue;

        if (file.type == MillerGui::FileType::File)
        {
            if (ImGui::TreeNodeEx(file.name.string().c_str(), ImGuiTreeNodeFlags_Leaf))
                ImGui::TreePop();
        }
        else if (file.type == MillerGui::FileType::Directory)
        {
            if (ImGui::TreeNodeEx(file.name.string().c_str(), ImGuiTreeNodeFlags_None))
            {
                if (file.name != "." && file.name != "..")
                {
                    createFileTree(file, fileManager);
                }
                ImGui::TreePop();
            }
        }
    }
}

void Explorer::OpenPath(const std::string& path)
{
    if (path.empty())
        return;
    if (path == ".")
        return;
    try {
        std::filesystem::path p(path);
        if (std::filesystem::exists(p) && MillerGui::FileManager::hasReadPermission(p))
        {
            currentPath = new std::string(p.string());
            fileManager->SetPath(p);
            fileManager->Restart();
        }
    }catch (std::filesystem::filesystem_error& e) {
        std::cerr << "Filesystem error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown error" << std::endl;
    }
    // fileManager->SetPath(path);
    // fileManager->Restart();
}

const MillerGui::FileObject* Explorer::copyFileObject = nullptr;
    /// @end TopWindow