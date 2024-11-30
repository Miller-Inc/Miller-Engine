//
// Created by James Miller on 11/29/2024.
//

#include "PracticeWindow.h"
#include <imgui.h>
#include "src/Windows/Capabilities.h"

namespace MillerGui {
    void PracticeWindow::RenderUI()
    {
        MillerIncGui::Capabilities::AddDockSpace();

        ImGui::Begin("Practice Window");

        ImGui::SetWindowSize(ImVec2(720, 480));

        ImVec2 size = ImVec2(ImGui::GetWindowSize().x * 0.75f,
            ImGui::GetWindowSize().y * 0.75f);
        ImTextureID tex_id = ImTextureID();

        char inputText[128] = "";
        ImGui::InputText("Input Text", inputText, IM_ARRAYSIZE(inputText));

        if (ImGui::IsKeyPressed(ImGuiKey_Enter))
        {
            tex_id = ImGui::GetIO().Fonts->TexID;
        }

        ImGui::Text("You entered: %s", inputText);

        ImGui::Image(tex_id, size, size);

        ImGui::End();
    }

} // MillerGUI