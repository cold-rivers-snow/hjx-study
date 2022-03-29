// main.c
#include <stdio.h>
#include <stdlib.h>
#include "myhook1.h"  //在myhook1时使用，如果不是1版本，可以注释掉。

int main() {
    int index;
    for (index=0; index < 10; index++) {
        char* p = (char*)malloc(4);
        printf("index:%d, p[0]=%d\n", index, *p);
        free(p);
    }
    printf("hello world\n");
    return 0;
}