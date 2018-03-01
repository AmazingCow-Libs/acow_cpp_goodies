#pragma once
// std
#include <cstdint>
#include <initializer_list>

//----------------------------------------------------------------------------//
//                                                                            //
// Private Function Declarations                                              //
//                                                                            //
//----------------------------------------------------------------------------//
namespace acow { namespace _private {

typedef std::initializer_list<uint32_t> flags_list_t;

bool flag_check_has_any(uint32_t var, const flags_list_t &others) noexcept;
bool flag_check_has_all(uint32_t var, const flags_list_t &others) noexcept;

bool flag_check_exclusivity(uint32_t var, const flags_list_t &others) noexcept;

} // namespace _private
} // namespace acow


//----------------------------------------------------------------------------//
//                                                                            //
// MACROS                                                                     //
//                                                                            //
//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
// Add / Remove                                                               //
//----------------------------------------------------------------------------//
#define _ACOW_PRIV_ACOW_FLAG_ADD(_what_, _var_) \
    ((_var_) |= (_what_))

#define _ACOW_PRIV_ACOW_FLAG_REMOVE(_what_, _var_)

//----------------------------------------------------------------------------//
// Has                                                                        //
//----------------------------------------------------------------------------//
#define _ACOW_PRIV_ACOW_FLAG_HAS(_what_, _var_) \
    ((_var_) & (_what_))

#define _ACOW_PRIV_ACOW_FLAG_HAS_ANY(_var_, _first_, ...) \
    acow::_private::flag_check_has_any(                   \
            (_var_),                                      \
            { uint32_t((_first_)), __VA_ARGS__ }          \
    )

#define _ACOW_PRIV_ACOW_FLAG_HAS_ALL(_var_, _first_, ...) \
    acow::_private::flag_check_has_all(                   \
            (_var_),                                      \
            { uint32_t((_first_)), __VA_ARGS__ }          \
    )


//----------------------------------------------------------------------------//
// Exclusivity                                                                //
//----------------------------------------------------------------------------//
#define _ACOW_PRIV_ACOW_FLAG_ARE_EXCLUSIVE(_var_, _first_, _second_, ...)  \
    acow::_private::flag_check_exclusivity(                                \
        (_var_),                                                           \
        { uint32_t((_first_)), uint32_t((_second_)),  __VA_ARGS__ }        \
    )
