#pragma once

// std
#include <memory>

namespace acow {

template<typename T, typename ...Args>
inline std::unique_ptr<T> make_unique( Args&& ...args )
{
    return std::unique_ptr<T>( new T( std::forward<Args>(args)... ) );
}

} // namespace acow


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

#define ACOW_SAFE_FREE          \
    do {                        \
        if(_ptr_) {             \
            free(_ptr_);        \
            _ptr_ = nullptr;    \
        }                       \
    } while(0)

