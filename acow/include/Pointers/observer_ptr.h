#pragma once

// std
#include <algorithm>
#include <functional>

namespace acow {

template <typename TYPE>
class observer_ptr
{
    //------------------------------------------------------------------------//
    // Enums / Constants / Typedefs                                           //
    //------------------------------------------------------------------------//
public:
    typedef TYPE  element_type;
    typedef TYPE *pointer;
    typedef TYPE &reference;


    //------------------------------------------------------------------------//
    // CTOR / DTOR                                                            //
    //------------------------------------------------------------------------//
public:
    constexpr observer_ptr() noexcept = default;

    constexpr observer_ptr(std::nullptr_t) noexcept
        : m_ptr(nullptr)
    {
        // Empty...
    }

    constexpr explicit observer_ptr(pointer p) noexcept
        : m_ptr(p)
    {
        // Empty...
    }


    //------------------------------------------------------------------------//
    // Public Methods                                                         //
    //------------------------------------------------------------------------//
public:
    constexpr pointer get() const noexcept { return m_ptr; }

    pointer release() noexcept
    {
        auto temp = m_ptr;
        reset();

        return temp;
    }

    void reset(pointer p = nullptr) noexcept { m_ptr = p; }


    //----------------------------------------------------------------------------//
    // Operators                                                                  //
    //----------------------------------------------------------------------------//
public:
    //--------------------------------------------------------------------------
    // Access.
    constexpr reference operator *() const          { return *m_ptr; }
    constexpr pointer   operator->() const noexcept { return m_ptr; }

    //--------------------------------------------------------------------------
    // Conversions.
    constexpr explicit operator bool   () const noexcept { return m_ptr; }
    constexpr explicit operator pointer() const noexcept { return m_ptr; }


    //------------------------------------------------------------------------//
    // iVars                                                                  //
    //------------------------------------------------------------------------//
private:
    pointer m_ptr;
};


//----------------------------------------------------------------------------//
// Operators                                                                  //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
//
template <typename TYPE1, typename TYPE2>
bool operator ==(observer_ptr<TYPE1> p1, observer_ptr<TYPE2> p2)
{
    return p1.get() == p2.get();
}

template <typename TYPE1, typename TYPE2>
bool operator !=(observer_ptr<TYPE1> p1, observer_ptr<TYPE2> p2)
{
    return !(p1 == p2);
}


//------------------------------------------------------------------------------
//
template <typename TYPE>
bool operator ==(observer_ptr<TYPE> p, std::nullptr_t) noexcept
{
    return !p;
}

template <typename TYPE>
bool operator ==(std::nullptr_t, observer_ptr<TYPE> p) noexcept
{
    return !p;
}

//------------------------------------------------------------------------------
//
template < typename TYPE >
bool operator !=(observer_ptr<TYPE> p, std::nullptr_t) noexcept
{
    return (bool)p;
}

template <typename TYPE>
bool operator !=(std::nullptr_t, observer_ptr<TYPE> p) noexcept
{
    return (bool)p;
}


//----------------------------------------------------------------------------//
// Helper Functions                                                           //
//----------------------------------------------------------------------------//
template <typename TYPE>
observer_ptr<TYPE> make_observer(TYPE *p) noexcept
{
    return observer_ptr<TYPE>(p);
}

} // namespace acow
