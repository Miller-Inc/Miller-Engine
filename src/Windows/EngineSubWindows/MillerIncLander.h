// Generated with ImRAD 0.8
// visit https://github.com/tpecholt/imrad

#pragma once
#include "imrad.h"
#include "Windows/SubWindowInterface.h"

class MillerIncLander : public MillerGui::SubWindowInterface
{
public:
    /// @begin interface
    void Open() override;
    void Close() override;
    void Draw() override;

    std::string* ProjectName = new std::string();
    std::string* FilePath = new std::string();
    /// @end interface

private:
    /// @begin impl
    void OpenProject();
    void NewProject();
    void SaveProject();
    void SaveAsProject();
    void GetHelp();
    void OpenAbout();

    bool isOpen = true;
    /// @end impl
};
