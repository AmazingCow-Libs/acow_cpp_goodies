//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Debugger.cpp                                                  //
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
#include "acow/include/Debugger.h"
// acow_cpp_goodies
#include "acow/include/OSMacros.h"
#include "acow/include/FakeKeywords.h"

#if (ACOW_OS_IS_GNU_LINUX)

//------------------------------------------------------------------------------
// Includes
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//------------------------------------------------------------------------------
// Implementation.
//   Copied from: https://stackoverflow.com/a/24969863
//   Thanks Sam Liao (https://stackoverflow.com/users/75501/sam-liao)
bool acow::IsDebuggerPresent() noexcept
{
    char buf[1024];
    int debugger_present = 0;

    int status_fd = open("/proc/self/status", O_RDONLY);
    if(status_fd == -1)
        return false;

    ssize_t num_read = read(status_fd, buf, sizeof(buf)-1);

    if (num_read > 0)
    {
        acow_local_persist const char kTracerPid[] = "TracerPid:";
        char *tracer_pid;

        buf[num_read] = 0;
        tracer_pid    = strstr(buf, kTracerPid);

        if(tracer_pid)
            debugger_present = !!atoi(tracer_pid + sizeof(kTracerPid) - 1);
    }

    return debugger_present;
}

#elif (ACOW_OS_IS_WINDOWS)
    // COWTODO(n2omatt): Implement for windows.
#else
    bool acow::IsDebuggerPresent() noexcept { return false; }
#endif
