#pragma once

#include <iostream>

template<typename T>
void printArray(T* array, int32_t size) {

    for(int32_t i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;
}