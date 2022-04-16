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

```
 g++ -o yeild yeild.cpp -lcolib -lpthread -ldl
```

## cmake

文本链接：
链接: https://pan.baidu.com/s/1-n2Kpz61ejcKFGwvofWWNA 
提取码: 6iuc 
### hello
- t1
在t1目录下编写main.c 和CMakeLists.txt文件后，执行`cmake .`构建。
这里根据参考中有个坑，`set(src_list main.c)  add_executable(hello ${src_list})` 
在add_executable 中需要的src_list变量的值，不是变量，所以需要加上${}，与shell类似，取值。
构建后，生成makefile文件，执行 make， 生成 二进制文件。 或者使用`make VERBOSE=1` 或
`VERBOSE=1 make` 生成，这样会打印更加详细的信息。

- t2
**任何子目录都需要有CMakeLists.txt 文件**

```
mkdir build
cd build
cmake ..
make
bin/hello
```

1，为⼯程添加⼀个⼦⽬录src，⽤来存储源代码;
2，添加⼀个⼦⽬录doc，⽤来存储这个⼯程的⽂档hello.txt
3，在⼯程⽬录添加⽂本⽂件COPYRIGHT, README；
4，在⼯程⽬录添加⼀个runhello.sh 脚本，⽤来调⽤hello ⼆进制
4，将构建后的⽬标⽂件放⼊构建⽬录的bin ⼦⽬录；
5，最终安装这些⽂件：将hello ⼆进制与runhello.sh 安装⾄/<prefix>/bin，将 doc ⽬录中的 hello.txt
以及COPYRIGHT/README 安装到/<prefix>/share/doc/cmake/t2，

现在进⼊build ⽬录进⾏外部编译，注意使⽤ CMAKE_INSTALL_PREFIX 参数，这⾥我们将它安装到
了/tmp/t2 ⽬录：
`cmake -DCMAKE_INSTALL_PREFIX=/tmp/t2/usr ..`
然后运⾏
`make`
`make install`
让我们进⼊/tmp/t2 ⽬录看⼀下安装结果：
```
./usr
./usr/share
./usr/share/doc
./usr/share/doc/cmake
./usr/share/doc/cmake/t2
./usr/share/doc/cmake/t2/hello.txt
./usr/share/doc/cmake/t2/README
./usr/share/doc/cmake/t2/COPYRIGHT
./usr/bin
./usr/bin/hello
./usr/bin/runhello.sh
```
如果你要直接安装到系统，可以使⽤如下指令：
`cmake -DCMAKE_INSTALL_PREFIX=/usr ..`


- t3 安装动态库
```
cmake -DCMAKE_INSTALL_PREFIX=/usr ..
make
make install
```

- t4 链接动态库

```
cmake ..
make

ldd bin/main   # 查看main使用的动态库
```

```
特殊的环境变量CMAKE_INCLUDE_PATH 和CMAKE_LIBRARY_PATH
直接使⽤了绝对路径INCLUDE_DIRECTORIES(/usr/include/hello)告诉⼯程这个头⽂件⽬录。
为了将程序更智能⼀点，我们可以使⽤ CMAKE_INCLUDE_PATH 来进⾏，使⽤bash 的⽅法如下：
export CMAKE_INCLUDE_PATH=/usr/include/hello
然后在头⽂件中将INCLUDE_DIRECTORIES(/usr/include/hello)替换为：
FIND_PATH(myHeader hello.h)
IF(myHeader)
INCLUDE_DIRECTORIES(${myHeader})
ENDIF(myHeader)

FIND_PATH ⽤来在指定路径中搜索⽂件名，⽐如：
FIND_PATH(myHeader NAMES hello.h PATHS /usr/include /usr/include/hello)
CMAKE_LIBRARY_PATH 可以⽤在 FIND_LIBRARY 中。
```

## workflow


# references
[微信协程库libco研究：hook系统函数](https://segmentfault.com/a/1190000012561446)

