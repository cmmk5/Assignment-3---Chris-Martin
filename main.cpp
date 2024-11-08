#include <iostream>
#include "Queue.h"
#include "lastOccurrence.h"
#include <vector>
using namespace std;

int main() {
    // Queue operations
    Queue<int> intQueue;

    // Push 10 values into the queue
    for (int i = 1; i <= 10; ++i) {
        intQueue.push(i);
    }

    // Display all elements in the queue
    cout << "Queue elements: ";
    while (!intQueue.empty()) {
        cout << intQueue.front() << " ";
        intQueue.move_to_rear();  // Move front to rear to cycle through all elements once
        intQueue.pop(); // Remove the element after displaying
    }
    cout << endl;


    // Testing lastOccurrence
    vector<int> vec = { 1, 2, 3, 4, 2, 5, 2, 6 };
    int target = 2;
    int lastIndex = lastOccurrence(vec, target, vec.size() - 1);

    if (lastIndex != -1) {
        cout << "The last occurrence of " << target << " is at index " << lastIndex << endl;
    }
    else {
        cout << target << " was not found in the vector." << endl;
    }

    return 0;
}
