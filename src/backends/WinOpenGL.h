//
// Created by James Miller on 11/29/2024.
//
#pragma once

#include "CrossPlatformMacros.h"

#if defined(WINDOWS) && OPEN_GL == true
#include <functional>

class WinOpenGL {
public:
    static int startWindow(std::function<void()> renderFunction);
};

#endif
