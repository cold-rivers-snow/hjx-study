// myhook.c
#include <stdlib.h>
#include <dlfcn.h>
#include <stdio.h>
#include "myhook1.h"

static int count = 0;

void *malloc(size_t size) {
    void *(*myMalloc)(size_t) = (void* (*)(size_t))dlsym(RTLD_NEXT, "malloc");
    count++;
    return myMalloc(size);
}

int enable_hook() {
    return count;
}