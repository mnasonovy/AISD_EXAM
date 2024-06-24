cmake_minimum_required(VERSION 3.11)

project(exam CXX)

if(MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS true)
    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
endif()

add_executable(search
    search.cc)
target_include_directories(search PRIVATE "${CMAKE_SOURCE_DIR}")

add_executable(sll
    single_linked_list.cc)
target_include_directories(sll PRIVATE "${CMAKE_SOURCE_DIR}")

add_executable(dll
    double_linked_list.cc)
target_include_directories(dll PRIVATE "${CMAKE_SOURCE_DIR}")

add_executable(insertion_sort
    insertion_sort.cc)
target_include_directories(insertion_sort PRIVATE "${CMAKE_SOURCE_DIR}")

add_executable(shell_and_selction_sort
    shell_and_selction_sort.cc)
target_include_directories(shell_and_selction_sort PRIVATE "${CMAKE_SOURCE_DIR}")

add_executable(bubble_shaker_quick_sort
    bubble_shaker_quick_sort.cc)
target_include_directories(bubble_shaker_quick_sort PRIVATE "${CMAKE_SOURCE_DIR}")

