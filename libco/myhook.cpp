// myhook.c
#include <stdlib.h>
#include <dlfcn.h>
#include <stdio.h>

int count = 0;

void *malloc(size_t size) {
    void *(*myMalloc)(size_t) = (void* (*)(size_t))dlsym(RTLD_NEXT, "malloc");
    count++;
    // 这里使用第一个字节为count数来表示程序进入了这个malloc函数
    char* data = (char*)myMalloc(size);
    *data = count;
    return (void*)data;
}

