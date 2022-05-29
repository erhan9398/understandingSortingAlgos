#include "utils.h"

void merge(int32_t* pArray, int32_t leftIndex, int32_t rigthIndex) {

    int32_t localTempSortedArraySize = rigthIndex - leftIndex + 1;
    int32_t temporarySortedArray[localTempSortedArraySize] = {};
    int32_t localMiddleIndex = (rigthIndex + leftIndex) / 2;
    int32_t localLeftIndex = leftIndex, localRightIndex = localMiddleIndex + 1, mainArrayIndex = 0;

    while(localLeftIndex <= localMiddleIndex && localRightIndex <= rigthIndex) {

        if(pArray[localLeftIndex] < pArray[localRightIndex]) {
            temporarySortedArray[mainArrayIndex++] = pArray[localLeftIndex++];
        } else {
            temporarySortedArray[mainArrayIndex++] = pArray[localRightIndex++];
        }
    }
    
    while(localLeftIndex <= localMiddleIndex) {
        temporarySortedArray[mainArrayIndex++] = pArray[localLeftIndex++];
    }
    while(localRightIndex <= rigthIndex) {
        temporarySortedArray[mainArrayIndex++] = pArray[localRightIndex++];
    }

    for (localLeftIndex = leftIndex; localLeftIndex <= rigthIndex; localLeftIndex++) {
        pArray[localLeftIndex] = temporarySortedArray[localLeftIndex - leftIndex];
    }
}

void mergeSort(int32_t* pArray, int32_t startIndex, int32_t endIndex) {

    // first, control the base case
    if (startIndex < endIndex) {

        int32_t middlePoint = (endIndex + startIndex) / 2;
        
        // call mergeSort() function recursively in order to sort left and right sides
        mergeSort(pArray, startIndex, middlePoint);
        mergeSort(pArray, middlePoint + 1, endIndex);
    
        // merge the two sub-arrays
        merge(pArray, startIndex, endIndex);
    }

}

int main() {
    
    std::cout << "This program sorts the array in mergeing manner" << std::endl;

    int32_t array[] = {7, 6, 5, 4, 3, 2};
    const int32_t size = sizeof(array) / sizeof(array[0]);
    
    std::cout << "before sorting" << std::endl;
    printArray(array, size);

    mergeSort(array, 0, size - 1);

    std::cout << "after sorting" << std::endl;
    printArray(array, size);

    return 0;
}