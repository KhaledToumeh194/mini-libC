// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	if (size == 0)
	{
		return NULL;
	}
	size_t align = sizeof(void *);
	size_t headers = (2 * sizeof(size_t) + (align - 1)) & ~(align - 1);
	size_t need = headers + size;
	void *base = mmap(NULL, need, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (base == MAP_FAILED)
	{
		return NULL;
	}
	((size_t *)base)[0] = size;
	((size_t *)base)[1] = need;
	return (void *)((char *)base + headers);
}

void *calloc(size_t nmemb, size_t size)
{
	if (nmemb && size > __SIZE_MAX__ / nmemb)
	{
		return NULL;
	}
	size_t total = nmemb * size;
	void *p = malloc(total);
	if (!p)
	{
		return NULL;
	}
	memset(p, 0, total);

	return p;
}

void free(void *ptr)
{
	if (!ptr)
	{
		return;
	}
	size_t align = sizeof(void *);
	size_t headers = (2 * sizeof(size_t) + (align - 1)) & ~(align - 1);
	void *base = (void *)((char *)ptr - headers);
	size_t need = ((size_t *)base)[1];
	munmap(base, need);
}

void *realloc(void *ptr, size_t size)
{
	if (!ptr)
	{
		return;
	}
	size_t alignas = sizeof(void *);
	size_t headers = (2 * sizeof(size_t) + (alignas - 1)) & ~(alignas - 1);
	void *base = (void *)((char *)ptr - headers);
	size_t oldsz = ((size_t *)base)[0];
	if (size <= oldsz)
	{
		return ptr;
	}
	void *np = malloc(size);
	if (!np)
	{
		return NULL;
	}
	memcpy(np, ptr, oldsz);
	free(ptr);
	return np;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	if (nmemb && size > __SIZE_MAX__ / nmemb)
	{
		return NULL;
	}

	return realloc(ptr, nmemb * size);
}
