# study

## libco

```
$ gcc -o main main.cpp
$ gcc -o libmymalloc.so -fPIC -shared -D_GNU_SOURCE myhook.cpp -ldl

$ LD_PRELOAD=./libmymalloc.so ./main

index:0, p[0]=1
index:1, p[0]=3
index:2, p[0]=4
index:3, p[0]=5
index:4, p[0]=6
index:5, p[0]=7
index:6, p[0]=8
index:7, p[0]=9
index:8, p[0]=10
index:9, p[0]=11
hello world
```

```
$ gcc -o libmymalloc.so -fPIC -shared -D_GNU_SOURCE myhook1.cpp -ldl
$ gcc main.cpp  -L . -Wl,-rpath . -lmymalloc -o main
$ ./main
index:0, hook res:0
index:1, hook res:2
index:2, hook res:3
index:3, hook res:4
index:4, hook res:5
index:5, hook res:6
index:6, hook res:7
index:7, hook res:8
index:8, hook res:9
index:9, hook res:10
hello world
```

### references
[微信协程库libco研究：hook系统函数](https://segmentfault.com/a/1190000012561446)

