//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : RawPointers.h                                                 //
//  Project   : acow_cpp_goodies                                              //
//  Date      : Mar 09, 2018                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2018                                             //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

#pragma once

#define ACOW_ARRAY_LENGTH(_array_) \
    sizeof((_array_)) / sizeof((_array_))

#define ACOW_SWAP_PTRS(_ptr1_, _ptr2_)     \
    do {                                   \
        decltype((_ptr1_)) tmp = (_ptr1_); \
        (_ptr1_) = (_ptr2_);               \
        (_ptr2_ )= tmp;                    \
    } while(0)