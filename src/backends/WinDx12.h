//
// Created by James Miller on 11/29/2024.
//

#pragma once


#include <locale>

#include "CrossPlatformMacros.h"
#include "Windows/MillerEngine.h"

#if DX12 == true
#include <functional>


// namespace MillerGui {

class WinDx12 {
public:
    static int startWindow (/*MillerEngine* miller_engine,*/ const std::string& windowTitle);
};

// } // MillerGui

#endif


