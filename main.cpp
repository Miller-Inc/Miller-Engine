#include <iostream>

#include "CrossPlatformMacros.h"
#include "src/Windows/MillerEngine.h"
#include "csignal"
#include "Workers/Logger.h"

// Include the correct backend
#ifdef DX12
    #include "src/backends/WinDx12.h"
    #define StartWindow WinDx12::startWindow
#elif defined(METAL)
    #error "Metal is not supported yet"
#elif defined(VULKAN)
    #error "Vulkan is not supported yet"
#elif defined(OPEN_GL)
    #error "OpenGL is not stable yet"
    #include "backends/WinOpenGL.h"
    #define StartWindow WinOpenGL::startWindow
#endif

void signalHandler(int signum)
{
    std::cout << "Interrupt signal (" << signum << ") received.\n";
    exit(signum);
}

int main(int argc, char* argv[])
{
    std::string fileName = MillerEngine::setup(argc, argv);

    if (fileName.empty())
    {
        fileName = std::filesystem::current_path().string();
    }

    auto engine = MillerEngine(); // Create the engine

    // Explorer temp = Explorer();
    engine.startEngine(fileName); // Start the engine

    StartWindow("Miller Engine");
    return 0;
}