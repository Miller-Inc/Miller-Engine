//
// Created by James Miller on 10/23/2024.
//

#pragma once

#define MDEBUG true

#if defined(_WIN32) || defined(_WIN64)
#define WINDOWS
#define DX12 true
#define OPEN_GL false
#elif defined(__APPLE__)
#define MACOS
#define METAL
#elif defined(__linux__)
#define LINUX
#define VULKAN
#define OPEN_GL true
#endif
