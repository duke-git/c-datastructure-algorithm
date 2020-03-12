cmake_minimum_required(VERSION 3.15)
project(c_datastructer C)

set(CMAKE_C_STANDARD 99)

add_executable(c_datastructer main.c link/linklist.c link/linklist.h link/link_test.c stack/stack.h stack/stack.c stack/stack_test.c queue/queue.h queue/queue.c queue/queue_test.c)