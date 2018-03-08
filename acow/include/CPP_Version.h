//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : CPP_Version.h                                                 //
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

#if (__cplusplus == 199711L)
    #define ACOW_CPP_98 1

#elif (__cplusplus == 201103L)
    #define ACOW_CPP_11 1

#elif (__cplusplus == 201402L)
    #define ACOW_CPP_14 1

#elif (__cplusplus == 201703L)
    #define ACOW_CPP_17 1

#else
    #define ACOW_CPP_UKNOWN 1

#endif
