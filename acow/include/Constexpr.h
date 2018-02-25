#pragma once

// acow_cpp_goodies
#include "CPP_Version.h"

#define ACOW_CONSTEXPR_STRICT constexpr

#if (ACOW_CPP_14 || ACOW_CPP_17)
    #define ACOW_CONSTEXPR_LOOSE constexpr

#elif (ACOW_CPP_11)
    #define ACOW_CONSTEXPR_LOOSE

#endif

