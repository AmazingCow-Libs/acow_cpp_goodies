//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : SmartPointer.h                                                //
//  Project   : acow_cpp_goodies                                              //
//  Date      : Jan 20, 2018                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2018                                             //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

#pragma once

// Headers
#include <memory> // Smart Pointers ;D

//----------------------------------------------------------------------------//
// Shared Pointer                                                             //
//----------------------------------------------------------------------------//
#define ACOW_SHARED_PTR_OF(_type_) \
    typedef std::shared_ptr<_type_> SPtr


//----------------------------------------------------------------------------//
// Unique Pointer                                                             //
//----------------------------------------------------------------------------//
#define ACOW_UNIQUE_PTR_OF(_type_) \
    typedef std::unique_ptr<_type_> UPtr

#define ACOW_UNIQUE_PTR_DELETER_OF(_type_, _func_) \
	typedef std::unique_ptr<_type_, _func_> UPtr;


//----------------------------------------------------------------------------//
// All Smart Pointers.                                                        //
//----------------------------------------------------------------------------//
#define ACOW_SMART_PTRS_OF(_type_) \
    ACOW_SHARED_PTR_OF(_type_);    \
    ACOW_UNIQUE_PTR_OF(_type_)
