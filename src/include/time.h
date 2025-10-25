#ifndef __TIME_H__
#define __TIME_H__ 1
#include <internal/types.h>
#include <sys/types.h>
#ifndef __time_t_defined
typedef long time_t;
#define __time_t_defined 1
#endif
#ifdef __cplusplus
extern "C"
{
#endif //
#ifndef __timespec_defined
#define __timespec_defined 1
    struct timespec
    {
        time_t tv_sec;
        long tv_nsec;
    };
#endif
    int nanosleep(const struct timespec *req, struct timespec *rem);
    unsigned int sleep(unsigned int seconds);
#ifdef __cplusplus
}
#endif
#endif
