#include <malloc.h>
#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>


int posix_memalign(void **memptr, size_t alignment, size_t size) {
    *memptr = memalign(alignment, size);
    return *memptr == NULL ? 1 : 0;
}

int openat(int dirfd, const char *pathname, int flags, ...) {
    assert(0 && "openat not supported");
    abort();
}

void flockfile(FILE *filehandle) {
}

void funlockfile(FILE *filehandle) {
}

ssize_t getline(char **lineptr, size_t *n, FILE *stream) {
    assert(0 && "getline not supported");
    abort();
}
