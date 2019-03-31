#ifndef STDLIB_ADD_STDIO_H
#define STDLIB_ADD_STDIO_H

#include_next <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

ssize_t getline(char **lineptr, size_t *n, FILE *stream);

#ifdef __cplusplus
}
#endif

#endif
