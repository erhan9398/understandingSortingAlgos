#include <iostream>

typedef struct testStruct_s {
    int id;
    std::string name;
}testStruct_s;


void printArray(int* pArr, int length) {
    for (int i = 0; i < length; i++) {
        std::cout << pArr[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void merge(T* pArray, int leftIndex, int rightIndex, bool(*compareFunc)(testStruct_s, testStruct_s)) {
    int midpoint = (leftIndex + rightIndex) / 2;
    int localLeft = leftIndex, localRight = midpoint + 1;
    T* localSortedArray = new T[rightIndex - leftIndex + 1];
    int localArrayIndex = 0;
    
    while(localLeft <= midpoint && localRight <= rightIndex) {
        if(compareFunc(pArray[localLeft], pArray[localRight])) {
            localSortedArray[localArrayIndex++] = pArray[localLeft++];
        }
        else {
            localSortedArray[localArrayIndex++] = pArray[localRight++];
        }
    }
    
    while(localLeft <= midpoint) {
        localSortedArray[localArrayIndex++] = pArray[localLeft++];
    }
    
    while(localRight <= rightIndex) {
        localSortedArray[localArrayIndex++] = pArray[localRight++];
    }
    
    for(int index = leftIndex; index <= rightIndex; index++) {
        pArray[index] = localSortedArray[index - leftIndex];
    }

    delete [] localSortedArray;
    
}

template<typename T>
void mergeSort(T* pArray, int startIndex, int endIndex, bool(*compareFunc)(testStruct_s, testStruct_s)) {
    
    if (startIndex < endIndex) {
        
        int middleIndex = (startIndex + endIndex) / 2;
#ifdef DEBUG_PRINT
        std::cout << "call first merge" << std::endl;
        std::cout << "start-mid-end " << startIndex << " " << middleIndex << " " << endIndex << std::endl;
#endif
        mergeSort<T>(pArray, startIndex, middleIndex, compareFunc);
#ifdef DEBUG_PRINT
        std::cout << std::string(30, '#') << std::endl;
        std::cout << "call second merge" << std::endl;
        std::cout << "start-mid-end " << startIndex << " " << middleIndex << " " << endIndex << std::endl;
#endif
        mergeSort<T>(pArray, middleIndex + 1, endIndex, compareFunc);
#ifdef DEBUG_PRINT
        std::cout << std::string(30, '#') << std::endl;
        std::cout << "call merge algo" << std::endl;
        std::cout << "start-end " << startIndex << " " << endIndex << std::endl;
#endif
        merge<T>(pArray, startIndex, endIndex, compareFunc);
    }
}


bool compareStruct(testStruct_s element1, testStruct_s element2) {
    return element1.id < element2.id;
}

template<typename T>
void swap(T& element1, T& element2) {
    T temp = element1;
    element1 = element2;
    element2 = temp;
}

void printStruct(testStruct_s* array, int length) {
    for(int i = 0; i < length; i++) {
        std::cout << array[i].name << " " << array[i].id << std::endl;
    }

}

int main() {
    
    testStruct_s a[] = {
        {
          .id = 34,
          .name = "istanbul"
        },
        {
            .id = 14,
            .name = "bolu"
        },
        {
            .id = 38,
            .name = "kayseri"
        },
        {
            .id = 1,
            .name = "adana"
        }
    };
    
    int arrayLength = sizeof(a)/sizeof(a[0]);

    int idArray[arrayLength];

    for(int i = 0; i < arrayLength; i++) {
        idArray[i] = a[i].id;
    }
    
    std::cout << "before sorting" << std::endl;
    printStruct(a, arrayLength);
    mergeSort<testStruct_s>(a, 0, arrayLength - 1, &compareStruct);
    std::cout << "after sorting" << std::endl;
    printStruct(a, arrayLength);

    return 0;
}