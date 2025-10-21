#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
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
	/* TODO: Implement strncpy(). */
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
	/* TODO: Implement strcat(). */
	char *dest = destination;
	while (*destination)
		destination++;
	while (*destination++ = *source++)
		;
	return dest;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
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
	/* TODO: Implement strcmp(). */
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
	/* TODO: Implement strncmp(). */
	while (len && *str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
		len--;
	}
	if (len == 0)
	{
		return 0;
	}
	else
	{
		return (*(unsigned char *)str1 - *(unsigned char *)str2);
	}
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	do
	{
		if (*str == c)
		{
			return str;
		}

	} while (*str++);

	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	char *isCFind = NULL;
	if (*str != NULL)
	{
		do
		{
			if (*str == (char)c)
			{
				isCFind = str;
			}

		} while (*str++);
		return isCFind;
	}

	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	char *a, *b = needle;
	if (*b == NULL)
	{
		return (char *)haystack;
	}
	for (; haystack != 0; haystack += 1)
	{
		if (*haystack != *b)
		{
			continue;
		}
		a = haystack;
		while (1)
		{
			if (*b == 0)
			{
				return (char *)haystack;
			}
			if (*a++ != *b++)
			{
				break;
			}
		}
		b = needle;
	}

	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	size_t Hlen = strlen(haystack);
	size_t Nlen = strlen(needle);
	if (Nlen == NULL)
	{
		return (char *)haystack;
	}
	if (Nlen > Hlen)
	{
		return NULL;
	}
	for (size_t i = Hlen - Nlen + 1; i-- > 0;)
	{
		for (size_t j = 0; j < Nlen; j++)
		{
			if (haystack[i + j] != needle[j])
			{
				break;
			}
			if (j == Nlen)
			{
				return (char *)(haystack + i);
			}
		}
	}

	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
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
	/* TODO: Implement memmove(). */
	char *tmp = (char *)num;
	char *cdst = (char *)destination;
	char *csrc = (char *)source;
	for (size_t i = 0; i < num; i++)
	{
		tmp[i] = cdst[i];
	}
	for (size_t i = 0; i < num; i++)
	{
		csrc[i] = tmp[i];
	}

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	const unsigned char *lhs = ptr1;
	const unsigned char *rhs = ptr2;

	for (size_t i = 0; i < num; i++)
	{
		if (lhs[i] > rhs[i])
		{
			return 1;
		}
		else if (lhs[i] < rhs[i])
		{
			return 1;
		}
	}

	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	return source;
}
