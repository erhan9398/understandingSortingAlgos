#include "utils.h"
void swap(int32_t* pArray, int32_t index1, int32_t index2) {
    int32_t temp = pArray[index1];
    pArray[index1] = pArray[index2];
    pArray[index2] = temp;    
}

void insertionSort(int32_t* pArray, int32_t size) {

    // comparison always start at 2nd index in array
    for(int32_t index = 1; index < size; index++) {
        
        // select pivot to compare ones on left
        int32_t pivot = pArray[index];
        
        // compare index starts with just left value of pivot
        int32_t comparedIndex = index - 1;
        
        // while pivot is less than left element and compare index is greater than zero, iterate comparison
        while(comparedIndex >= 0 && pArray[comparedIndex] > pivot) {
            // if pivot is less than just left element and comparison is greater than zero, then swap two elements
            swap(pArray, comparedIndex, comparedIndex+1);
            // decrease comparison index by one
            comparedIndex--;
        }
    }

}

int main() {

    std::cout << "This program sorts the array in insertion manner" << std::endl;

    int32_t unsortedArray[] = {
        9, 8, 7, 6, 5, 4, 3, 2, 1
    };

    int32_t sizeOfArray = sizeof(unsortedArray) / sizeof(unsortedArray[0]);

    std::cout << "array before sorting" << std::endl;
    printArray(unsortedArray, sizeOfArray);

    //sort array in insertion method
    insertionSort(unsortedArray, sizeOfArray);
    std::cout << "array after sorting" << std::endl;
    printArray(unsortedArray, sizeOfArray);

    return 0;
}
