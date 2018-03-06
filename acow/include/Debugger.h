#pragma once

namespace acow {

bool IsDebuggerPresent() noexcept;

} // namespace acow

#define ACOW_DEBUGGER_BREAK()    \
    do {                         \
        if(acow::IsDebuggerPresent()){ \
            __asm__("int3");     \
        }                        \
    } while(0)
