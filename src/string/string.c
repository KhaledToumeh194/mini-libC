#include <string.h>

char *strcpy(char *destination, const char *source)
{
	int i = 0;
	while (1)
	{
		destination[i] = source[i];
		if (destination[i] == '\0')
		{
			break;
		}
		i++;
	}

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	if (destination == NULL || source == NULL || len == 0)
	{
		return destination;
	}
	size_t i = 0;
	while (i < len && source[i] != '\0')
	{
		destination[i] = source[i];
		i++;
	}
	while (i < len)
	{
		destination[i] = '\0';
		i++;
	}
	return destination;
}

char *strcat(char *destination, const char *source)
{
	char *dest = destination;
	while (*destination)
		destination++;
	while (*destination++ = *source++)
		;
	return dest;
}

char *strncat(char *destination, const char *source, size_t len)
{
	char *d = destination;
	while (*d)
		d++;
	while (len-- && *source)
		*d++ = *source++;
	*d = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	int i = 0;
	while ((*str1 != '\0') || (*str2 != '\0'))
	{
		if (*str1 > *str2)
		{
			return 1;
		}
		if (*str1 < *str2)
		{
			return -1;
		}
		str1++;
		str2++;
	}

	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	while (len && *str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
		len--;
	}
	if (len == 0)
	{
		return 0;
	}else{
		return (*(unsigned char *)str1 - *(unsigned char *)str2);
	}
}

size_t strlen(const char *str)
{
	size_t i = 0;
	for (; *str != '\0'; str++, i++)
	{
	};
	return i;
}

char *strchr(const char *str, int c)
{
	unsigned char ch = (unsigned char)c;
	const char *p = str;
	for (; *p; p++)
		if ((unsigned char)*p == ch)
			return (char *)p;
	return (ch == '\0') ? (char *)p : NULL;
}

char *strrchr(const char *str, int c)
{
	unsigned char ch = (unsigned char)c;
	const char *last = NULL, *p = str;
	for (; *p; p++)
		if ((unsigned char)*p == ch)
			last = p;
	if (ch == '\0')
		return (char *)p;
	return (char *)last;
	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	const char *h = haystack, *n = needle;

	if (*n == '\0')
		return (char *)h;
	for (; *h; h++)
	{
		const char *a = h, *b = n;
		while (*a && *b && *a == *b)
		{
			a++;
			b++;
		}
		if (*b == '\0')
			return (char *)h;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	if (!*needle)
		return (char *)haystack;

	const char *last = NULL;
	for (const char *p = haystack; *p; p++)
	{
		const char *a = p, *b = needle;
		while (*a && *b && *a == *b)
		{
			a++;
			b++;
		}
		if (!*b)
			last = p;
	}
	return (char *)last;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	char *csrc = (char *)source;
	char *cdst = (char *)destination;
	for (size_t i = 0; i < num; i++)
	{
		cdst[i] = csrc[i];
	}
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	unsigned char *d = (unsigned char *)destination;
	const unsigned char *s = (const unsigned char *)source;
	if (d == s || num == 0)
		return destination;
	if (d < s)
	{
		for (size_t i = 0; i < num; i++)
			d[i] = s[i];
	}else{
		for (size_t i = num; i != 0; i--)
			d[i - 1] = s[i - 1];
	}
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	const unsigned char *lhs = ptr1;
	const unsigned char *rhs = ptr2;
	for (size_t i = 0; i < num; i++)
	{
		if (lhs[i] > rhs[i])
		{
			return 1;
		}else if (lhs[i] < rhs[i]){
			return 1;
		}
	}

	return 0;
}

void *memset(void *source, int value, size_t num)
{
	unsigned char *src = source;
	while (num > 0)
	{
		*src = (unsigned char)value;
		src++;
		num--;
	}

	return source;
}
