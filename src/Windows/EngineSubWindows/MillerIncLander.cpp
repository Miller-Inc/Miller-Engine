// Generated with ImRAD 0.8
// visit https://github.com/tpecholt/imrad

#include "MillerIncLander.h"

MillerIncLander millerIncLander;

void MillerIncLander::Draw()
{
    /// @style Dark
    /// @unit px
    /// @begin TopWindow
    // auto* ioUserData = (ImRad::IOUserData*)ImGui::GetIO().UserData;
    ImGui::PushStyleColor(ImGuiCol_WindowBg, 0xff7f817f);
    ImGui::PushStyleColor(ImGuiCol_MenuBarBg, 0xff323432);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
    ImGui::SetNextWindowSize({ 720, 480 }, ImGuiCond_FirstUseEver); //{ 720, 480 }
    if (isOpen && ImGui::Begin("Miller Inc Physics Engine###MillerIncLander", &isOpen, ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_MenuBar))
    {
        /// @separator

        // TODO: Add Draw calls of dependent popup windows here

        /// @begin MenuBar
        if (ImGui::BeginMenuBar())
        {
            /// @separator

            /// @begin MenuIt
            if (ImGui::BeginMenu("File"))
            {
                /// @separator

                /// @begin MenuIt
                ImGui::MenuItem("Open...", "", false);
                if (ImGui::IsItemClicked())
                    OpenProject();
                /// @end MenuIt

                /// @begin MenuIt
                ImGui::MenuItem("New Project", "", false);
                if (ImGui::IsItemClicked())
                    NewProject();
                /// @end MenuIt

                /// @begin MenuIt
                ImGui::MenuItem("Save", "", false);
                if (ImGui::IsItemClicked())
                    SaveProject();
                /// @end MenuIt

                /// @begin MenuIt
                ImGui::MenuItem("Save As...", "", false);
                if (ImGui::IsItemClicked())
                    SaveAsProject();
                /// @end MenuIt

                /// @separator
                ImGui::EndMenu();
            }
            /// @end MenuIt

            /// @begin MenuIt
            if (ImGui::BeginMenu("Help"))
            {
                /// @separator

                /// @begin MenuIt
                ImGui::MenuItem("Get Help...", "", false);
                if (ImGui::IsItemClicked())
                    GetHelp();
                /// @end MenuIt

                /// @begin MenuIt
                ImGui::MenuItem("About", "", false);
                if (ImGui::IsItemClicked())
                    OpenAbout();
                /// @end MenuIt

                /// @separator
                ImGui::EndMenu();
            }
            /// @end MenuIt

            /// @begin MenuIt
            ImGui::MenuItem("View", "", false);
            /// @end MenuIt

            /// @separator
            ImGui::EndMenuBar();
        }
        /// @end MenuBar

        /// @begin Text
        ImGui::TextUnformatted("Project Name");
        /// @end Text

        /// @begin Input
        ImGui::SameLine(0, 1 * ImGui::GetStyle().ItemSpacing.x);
        ImGui::SetNextItemWidth(400);

        char projCharIpt[256] = "";

        ImGui::InputText("##00", projCharIpt, IM_ARRAYSIZE(projCharIpt), ImGuiInputTextFlags_None);

        ProjectName = new std::string(projCharIpt);

        // if (ImGui::IsItemActive())
            // ioUserData->imeType = ImRad::ImeText;
        /// @end Input

        /// @begin Button
        ImGui::SameLine(0, 1 * ImGui::GetStyle().ItemSpacing.x);
        ImGui::Button("OK", { 0, 0 });
        if (ImGui::IsItemHovered(ImGuiHoveredFlags_DelayNormal))
            ImGui::SetTooltip("Create Project");
        /// @end Button

        /// @begin Text
        ImGui::TextUnformatted("Save Path");
        /// @end Text

        /// @begin Input
        ImGui::SameLine(0, 1 * ImGui::GetStyle().ItemSpacing.x);
        ImGui::SetNextItemWidth(400);

        char projectSaveDir[4096] = "";
        ImGui::InputText("##01", projectSaveDir, IM_ARRAYSIZE(projectSaveDir));


        FilePath = new std::string(projectSaveDir);

        // if (ImGui::IsItemActive())
            // ioUserData->imeType = ImRad::ImeText;
        /// @end Input

        /// @begin Text
        ImGui::TextUnformatted("Project Type");
        /// @end Text

        /// @begin Child
        ImGui::BeginChild("child1", { -1, -1 }, ImGuiChildFlags_AlwaysUseWindowPadding | ImGuiChildFlags_NavFlattened, ImGuiWindowFlags_NoSavedSettings);
        {
            /// @separator

            /// @begin CollapsingHeader
            ImGui::SetNextItemOpen(true, ImGuiCond_Appearing);
            if (ImGui::CollapsingHeader("Sample Projects"))
            {
                /// @separator

                /// @begin Child
                ImGui::BeginChild("child2", { -1, -1 }, ImGuiChildFlags_AlwaysUseWindowPadding | ImGuiChildFlags_NavFlattened, ImGuiWindowFlags_NoSavedSettings);
                {
                    /// @separator

                    /// @begin TreeNode
                    ImGui::SetNextItemOpen(true, ImGuiCond_Appearing);
                    if (ImGui::TreeNodeEx("Simple Projects", ImGuiTreeNodeFlags_None))
                    {
                        /// @separator

                        /// @begin TreeNode
                        ImGui::SetNextItemOpen(true, ImGuiCond_Appearing);
                        if (ImGui::TreeNodeEx("Minimal Example", ImGuiTreeNodeFlags_Leaf))
                        {
                            /// @separator

                            /// @separator
                            ImGui::TreePop();
                        }
                        /// @end TreeNode

                        /// @begin TreeNode
                        ImGui::SetNextItemOpen(true, ImGuiCond_Appearing);
                        if (ImGui::TreeNodeEx("Blank (Empty)", ImGuiTreeNodeFlags_Leaf))
                        {
                            /// @separator

                            /// @separator
                            ImGui::TreePop();
                        }
                        /// @end TreeNode

                        /// @separator
                        ImGui::TreePop();
                    }
                    /// @end TreeNode

                    /// @begin TreeNode
                    if (false)
                    {
                        //visible
                        ImGui::SetNextItemOpen(false, ImGuiCond_Appearing);
                        if (ImGui::TreeNodeEx("Examples", ImGuiTreeNodeFlags_None))
                        {
                            /// @separator

                            /// @separator
                            ImGui::TreePop();
                        }
                    }
                    /// @end TreeNode

                    /// @separator
                    // ImGui::EndChild();
                }
                ImGui::EndChild();
                /// @end Child

                /// @separator
            }
            /// @end CollapsingHeader

        }
        /// @separator
        ImGui::EndChild();
        /// @end Child

        /// @separator
        ImGui::End();
    }
    ImGui::PopStyleVar();
    ImGui::PopStyleColor();
    ImGui::PopStyleColor();
    /// @end TopWindow
}

void MillerIncLander::OpenProject()
{
}

void MillerIncLander::NewProject()
{
}

void MillerIncLander::SaveProject()
{
}

void MillerIncLander::SaveAsProject()
{
}

void MillerIncLander::GetHelp()
{
}

void MillerIncLander::OpenAbout()
{
}

// void MillerIncLander::Open REMOVED

// void MillerIncLander::Close REMOVED

void MillerIncLander::Open()
{
    isOpen = true;
}

void MillerIncLander::Close()
{
    isOpen = false;
}
