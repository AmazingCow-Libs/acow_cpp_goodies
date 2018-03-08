//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Constexpr.h                                                   //
//  Project   : acow_cpp_goodies                                              //
//  Date      : Feb 23, 2018                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2018                                             //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

#pragma once

// acow_cpp_goodies
#include "CPP_Version.h"

#define ACOW_CONSTEXPR_STRICT constexpr

#if (ACOW_CPP_14 || ACOW_CPP_17)
    #define ACOW_CONSTEXPR_LOOSE constexpr

#elif (ACOW_CPP_11)
    #define ACOW_CONSTEXPR_LOOSE

#endif
