#include <time.h>
#include <errno.h>
#include <internal/syscall.h>
#include <internal/arch/x86_64/syscall_list.h>
#define NSEC_PER_SEC 1000000000L
int nanosleep(const struct timespec *req, struct timespec *rem)
{
    if (!req || req->tv_nsec < 0 || req->tv_nsec >= NSEC_PER_SEC)
    {
        errno = EINVAL;
        return -1;
    }
    long rc = syscall(__NR_nanosleep, (long)req, (long)rem);
    if (rc < 0)
    {
        errno = (int)-rc;
        return -1;
    }
    return 0;
}
unsigned int sleep(unsigned int seconds)
{
    if (seconds == 0)
    {
        return 0;
    }
    struct timespec req = {.tv_sec = (time_t)seconds, .tv_nsec = 0};
    struct timespec rem;
    if (nanosleep(&req, &rem) == 0)
    {
        return 0;
    }
    if (errno == EINTR)
    {
        unsigned int remain;
        if (rem.tv_sec <= 0)
        {
            remain = 0U;
        }else if (rem.tv_sec >= (time_t)seconds){
            remain = seconds;
        }else{
            remain = (unsigned int)rem.tv_sec;
        }
        if (rem.tv_nsec > 0 && remain < seconds)
        {
            remain++;
        }
        return remain;
    }
    return seconds;
}
