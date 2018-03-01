#pragma once

//------------------------------------------------------------------------------
// Private stuff...
//   Should not be used by consumers of this lib.
#include "private/BitwiseUtils.h"


//----------------------------------------------------------------------------//
// Add / Remove                                                               //
//----------------------------------------------------------------------------//
#define ACOW_FLAG_ADD(_what_, _var_) \
    _ACOW_PRIV_ACOW_FLAG_ADD(_what_, _var_)

#define ACOW_FLAG_REMOVE(_what_, _var_) \
    _ACOW_PRIV_ACOW_FLAG_REMOVE(_what_, _var_)


//----------------------------------------------------------------------------//
// Has                                                                        //
//----------------------------------------------------------------------------//
#define ACOW_FLAG_HAS(_what_, _var_) \
    _ACOW_PRIV_ACOW_FLAG_HAS(_what_, _var_)

#define ACOW_FLAG_HAS_ANY(_var_, _first_, ...) \
    _ACOW_PRIV_ACOW_FLAG_HAS_ANY(_var_, _first_, __VA_ARGS__)

#define ACOW_FLAG_HAS_ALL(_var_, _first_, ...) \
    _ACOW_PRIV_ACOW_FLAG_HAS_ALL(_var_, _first_, __VA_ARGS__)


//----------------------------------------------------------------------------//
// Exclusivity                                                                //
//----------------------------------------------------------------------------//
#define ACOW_FLAG_ARE_EXCLUSIVE(_var_, _first_, _second_, ...) \
    _ACOW_PRIV_ACOW_FLAG_ARE_EXCLUSIVE(_var_, _first_, _second_, __VA_ARGS__)
