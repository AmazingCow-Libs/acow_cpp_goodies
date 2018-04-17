#pragma once

// AmazingCow Libs
#include "acow/c_goodies.h"

#define ACOW_ASSERT_STDSTR_NOT_EMPTY(_str_) \
    ACOW_ASSERT_CSTR_NOT_EMPTY(_str_.c_str())

#define ACOW_ASSERT_NOT_STDSTR_EMPTY_OR_WHITESPACE(_str_) \
    ACOW_ASSERT_NOT_CSTR_EMPTY_OR_WHITESPACE(_str_.c_str())