//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Disallow.h                                                    //
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

//----------------------------------------------------------------------------//
// CTOR / DTOR                                                                //
//----------------------------------------------------------------------------//
#define ACOW_DISALLOW_CTOR(_type_)  _type_() = delete;
#define ACOW_DISALLOW_DTOR(_type_) ~_type_() = delete;

#define ACOW_DISALLOW_CTOR_DTOR(_type_) \
    ACOW_DISALLOW_CTOR(_type_)          \
    ACOW_DISALLOW_DTOR(_type_)


//----------------------------------------------------------------------------//
// Copy                                                                       //
//----------------------------------------------------------------------------//
#define ACOW_DISALLOW_COPY_CTOR(_type_) \
    _type_(const _type_ &) = delete;

#define ACOW_DISALLOW_COPY_ASSIGN(_type_) \
    _type_& operator=(const _type_&) = delete;

#define ACOW_DISALLOW_COPY_CTOR_AND_COPY_ASSIGN(_type_) \
    ACOW_DISALLOW_COPY_CTOR(_type_)                     \
    ACOW_DISALLOW_COPY_ASSIGN(_type_)


//----------------------------------------------------------------------------//
// Move                                                                       //
//----------------------------------------------------------------------------//
#define ACOW_DISALLOW_MOVE_CTOR(_type_) \
    _type_(const _type_ &&) = delete;

#define ACOW_DISALLOW_MOVE_ASSIGN(_type_) \
    _type_& operator=(const _type_&&) = delete;

#define ACOW_DISALLOW_MOVE_CTOR_AND_MOVE_ASSIGN(_type_) \
    ACOW_DISALLOW_MOVE_CTOR(_type_)                     \
    ACOW_DISALLOW_MOVE_ASSIGN(_type_)


//----------------------------------------------------------------------------//
// Everything                                                                 //
//----------------------------------------------------------------------------//
#define ACOW_DISALLOW_EVERYTHING(_type_)            \
    ACOW_DISALLOW_CTOR_DTOR(_type_)                 \
    ACOW_DISALLOW_COPY_CTOR_AND_COPY_ASSIGN(_type_) \
    ACOW_DISALLOW_MOVE_CTOR_AND_MOVE_ASSIGN(_type_)
