
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


//----------------------------------------------------------------------------//
// All Smart Pointers.                                                        //
//----------------------------------------------------------------------------//
#define ACOW_SMART_PTRS_OF(_type_) \
    ACOW_SHARED_PTR_OF(_type_);    \
    ACOW_UNIQUE_PTR_OF(_type_)
