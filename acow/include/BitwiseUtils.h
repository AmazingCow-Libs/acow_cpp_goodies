#pragma once


#define ACOW_FLAG_ADD(_what_, _var_) _var_ |= _what_

#define ACOW_FLAG_HAS(_what_, _var_) _var_ & _what_