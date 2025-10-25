
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <internal/io.h>

int puts(const char *s)
{
    if (!s)
    {
        errno = EINVAL;
        return -1;
    }
    size_t len = 0;
    while (s[len] != '\0')
        len++;

    if (write(1, s, len) < 0)
        return -1;

    if (write(1, "\n", 1) < 0)
        return -1;

    return 0;
}
