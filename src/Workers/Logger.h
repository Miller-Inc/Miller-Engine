//
// Created by James Miller on 12/3/2024.
//

#pragma once

#if defined NDEBUG
#define LOG(x) std::cout << x << "\n"
#define LOG_ERROR(x) std::cerr << x << "\n"
#else
#define LOG(x)
#define LOG_ERROR(x)
#endif


namespace MillerGui {

class Logger {

};

} // MillerGui

