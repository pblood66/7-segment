#include "clock.h"
#include <time.h>

int getHour()
{
    return getLocal()->tm_hour;
}

int getMinutes()
{
    return getLocal()->tm_min;
}

int getSeconds()
{
    return getLocal()->tm_sec;
}

struct tm* getLocal() {
    time_t raw = time(NULL);
    return localtime(&raw);
}
