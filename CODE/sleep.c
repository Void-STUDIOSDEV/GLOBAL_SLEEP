#include "sleep.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <time.h> // Required for nanosleep
#endif

void sleep(double seconds) {
#ifdef _WIN32
    // Windows Sleep takes milliseconds
    Sleep((DWORD)(seconds * 1000.0));
#else
    // POSIX nanosleep takes seconds and nanoseconds
    struct timespec ts;
    ts.tv_sec = (time_t)seconds;                                      // Whole seconds
    ts.tv_nsec = (long)((seconds - (double)ts.tv_sec) * 1e9);         // Remaining nanoseconds
    
    nanosleep(&ts, NULL);
#endif
}