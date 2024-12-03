//
// Created by James Miller on 11/29/2024.
//

#include "Explorer.h"
#include <imgui.h>
#include <iostream>

Explorer::Explorer()
{
    isOpen = false;
    fileManager = new MillerGui::FileManager(std::filesystem::current_path());
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
        ImGui::InputText("###ExplorerTextInput", inputText, IM_ARRAYSIZE(inputText));

        input = new std::string(inputText);

        if (ImGui::IsItemActive())
            if (ImGui::IsItemHovered(ImGuiHoveredFlags_DelayShort))
                ImGui::SetTooltip("Search for file or folder");

        MillerGui::FileObject fileLayout = fileManager->GetFileLayout();


        createFileTree(fileLayout);

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

void Explorer::createFileTree(const MillerGui::FileObject& fileHead)
{
    for (auto & file : fileHead.children)
    {
        if (file.type == MillerGui::FileType::File)
        {
            if (ImGui::TreeNodeEx(file.name.string().c_str(), ImGuiTreeNodeFlags_Leaf))
                ImGui::TreePop();
        }
        else if (file.type == MillerGui::FileType::Directory)
        {
            if (ImGui::TreeNodeEx(file.name.string().c_str(), ImGuiTreeNodeFlags_None))
            {
                createFileTree(file);
                ImGui::TreePop();
            }
        }
    }
}
    /// @end TopWindow