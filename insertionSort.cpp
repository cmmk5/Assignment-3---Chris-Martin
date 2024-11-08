#include "insertionSort.h"
#include <iostream>

template <typename T>
void insertionSort(Queue<T>& intQueue) {
    Queue<T> sortedQueue;

    // Iterate over the elements in the original queue
    while (!intQueue.empty()) {
        T current = intQueue.front();
        intQueue.pop();

        // Insert the current element in the sorted queue
        while (!sortedQueue.empty() && sortedQueue.front() < current) {
            intQueue.push(sortedQueue.front());
            sortedQueue.pop();
        }

        sortedQueue.push(current);
    }

    // Transfer the sorted elements back to the original queue
    while (!sortedQueue.empty()) {
        intQueue.push(sortedQueue.front());
        sortedQueue.pop();
    }
}

// Explicit template instantiations for int
template void insertionSort<int>(Queue<int>&);
