cmake_minimum_required(VERSION 3.10.2)

project(SortingAlgorithms
        VERSION 1.0
        LANGUAGES CXX)

#option(SORT_TYPE "which sorting will be used" ${var})

if("${SORT_TYPE}" STREQUAL "insert")
    set(SOURCES insertionSort.cpp)
endif()
if("${SORT_TYPE}" STREQUAL "merge")
    set(SOURCES mergeSort.cpp)    
endif()

if(NOT "${SOURCES}" STREQUAL "")
    add_executable(sort ${SOURCES})
endif()

message("sorting type is ${SORT_TYPE}")