//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : BitwiseUtils.cpp                                              //
//  Project   : acow_cpp_goodies                                              //
//  Date      : Feb 23, 2018                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2018                                             //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

// Header
#include "acow/include/private/BitwiseUtils.h"
// std
#include <iterator>

//----------------------------------------------------------------------------//
//                                                                            //
// Private Function Definitions                                               //
//                                                                            //
//----------------------------------------------------------------------------//
bool acow::_private::flag_check_has_any(
    uint32_t            var,
    const flags_list_t &others) noexcept
{
    for(auto &value : others)
    {
        if(_ACOW_PRIV_ACOW_FLAG_HAS(value, var))
            return true;
    }

    return false;
}

bool acow::_private::flag_check_has_all(
    uint32_t           var,
    const flags_list_t &others) noexcept
{
    for(auto &value : others)
    {
        if(!_ACOW_PRIV_ACOW_FLAG_HAS(value, var))
            return false;
    }

    return true;
}

bool acow::_private::flag_check_exclusivity(
    uint32_t            var,
    const flags_list_t &others) noexcept
{
    auto it = others.begin();
    auto curr_value = _ACOW_PRIV_ACOW_FLAG_HAS(*it, var);
    std::advance(it, 1);

    while(it != others.end())
    {
        curr_value ^= _ACOW_PRIV_ACOW_FLAG_HAS(*it, var);
        ++it;
    }

    return curr_value;
}
