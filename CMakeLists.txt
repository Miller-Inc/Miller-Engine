cmake_minimum_required(VERSION 3.29)
project(Miller_GUI)

set(CMAKE_CXX_STANDARD 20)

include_directories(ThirdParty/imgui)
include_directories(ThirdParty/glfw)
include_directories(ThirdParty/glfw/include/GLFW)
include_directories(ThirdParty/glfw/include)
include_directories(ThirdParty/glfw/deps/glad)
include_directories(ThirdParty/glfw/deps/mingw)
include_directories(ThirdParty/glfw/deps/wayland
                    ${PROJECT_SOURCE_DIR})
include_directories(src)



add_executable(Miller_GUI main.cpp
        ThirdParty/imgui/imconfig.h
        ThirdParty/imgui/imgui.h
        ThirdParty/imgui/imgui.cpp
        ThirdParty/imgui/imgui_demo.cpp
        ThirdParty/imgui/imgui_draw.cpp
        ThirdParty/imgui/imgui_internal.h
        ThirdParty/imgui/imgui_tables.cpp
        ThirdParty/imgui/imgui_widgets.cpp
        ThirdParty/imgui/imstb_rectpack.h
        ThirdParty/imgui/imstb_textedit.h
        ThirdParty/imgui/imstb_truetype.h
        ThirdParty/imgui/backends/imgui_impl_dx12.h
        ThirdParty/imgui/backends/imgui_impl_win32.h
        ThirdParty/imgui/backends/imgui_impl_dx12.cpp
        ThirdParty/imgui/backends/imgui_impl_win32.cpp
        src/Windows/PracticeWindow.cpp
        src/Windows/Capabilities.cpp
        src/Windows/Capabilities.h
        src/Windows/MillerEngine.cpp
        src/Windows/MillerEngine.h
        src/Windows/MillerEngine.h
        src/Windows/EngineSubWindows/Explorer.cpp
        src/Windows/EngineSubWindows/Explorer.h
        src/Windows/EngineSubWindows/Explorer.h
        CrossPlatformMacros.h
        ThirdParty/glfw/include/GLFW/glfw3.h
        ThirdParty/glfw/include/GLFW/glfw3native.h
        src/Windows/SubWindowInterface.h
        src/backends/WinDx12.cpp
        src/backends/WinDx12.h
        src/Windows/EngineSubWindows/MillerIncLander.h
        src/Windows/EngineSubWindows/MillerIncLander.cpp
        ThirdParty/imgui/imrad.h
        src/Workers/FileSystems/FileManager.cpp
        src/Workers/FileSystems/FileManager.h
        src/Workers/FileSystems/FileManager.h
        src/Workers/FileSystems/FileObject.h
        src/Workers/Logger.cpp
        src/Workers/Logger.h
)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    message(STATUS "Running on Windows")
    target_link_libraries(Miller_GUI d3d12.lib d3dcompiler.lib dxgi.lib)
    set(GLFW_PATH ${PROJECT_SOURCE_DIR}/ThirdParty/glfw/glfw3.lib)
    # Link DirectX 12 libraries
#    target_link_libraries(Miller_GUI PRIVATE d3d12 dxgi)

    # Include directories
#    target_include_directories(Miller_GUI PRIVATE ${D3D12_INCLUDE_DIRS} ${DXGI_INCLUDE_DIRS})

elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    message(STATUS "Running on Linux")
    set(GLFW_PATH ${PROJECT_SOURCE_DIR}/ThirdParty/glfw/libglfw3.a)
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    message(STATUS "Running on macOS")
    set(GLFW_PATH ${PROJECT_SOURCE_DIR}/ThirdParty/glfw/libglfw3.a)
else()
    message(STATUS "Unknown OS")
    set(GLFW_PATH ${PROJECT_SOURCE_DIR}/ThirdParty/glfw/libglfw3.a)
endif()

target_link_libraries(Miller_GUI ${GLFW_PATH})
