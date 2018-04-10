//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Memory.h                                                      //
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

// std
#include <memory>

namespace acow 
{
//----------------------------------------------------------------------------//
// unique_ptr                                                                 //
//----------------------------------------------------------------------------//
template<typename T, typename ...Args>
inline std::unique_ptr<T> make_unique( Args&& ...args )
{
    return std::unique_ptr<T>( new T( std::forward<Args>(args)... ) );
}

//----------------------------------------------------------------------------//
// Memory                                                                     //
//----------------------------------------------------------------------------//
namespace Memory { 
    template <typename T> void 
    Clear(T &t) noexcept
    { 
        std::memset(&t, 0, sizeof(T));
    }

    template <typename T> void
    Clear(T *&t) { 
        static_assert(false, "Value types only...");
    }
} // namespace Memory

} // namespace acow

//----------------------------------------------------------------------------//
// Macros                                                                     //
//----------------------------------------------------------------------------//
#define ACOW_SAFE_DELETE(_ptr_) \
    do {                        \
        if(_ptr_) {             \
            delete _ptr_;       \
            _ptr_ = nullptr;    \
        }                       \
    } while(0)

#define ACOW_SAFE_DELETE_ARR(_ptr_) \
    do {                            \
        if(_ptr_) {                 \
            delete [] _ptr_;        \
            _ptr_ = nullptr;        \
        }                           \
    } while(0)
