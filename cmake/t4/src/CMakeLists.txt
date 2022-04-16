ADD_EXECUTABLE(main main.c)
INCLUDE_DIRECTORIES(/tmp/t3/include/hello)
TARGET_LINK_LIBRARIES(main /tmp/t3/lib/libhello.so)
# TARGET_LINK_LIBRARIES(main hello)  与上面相同，只是一个全名一个简名。
# TARGET_LINK_LIBRARIES(main libhello.a) 链接静态库