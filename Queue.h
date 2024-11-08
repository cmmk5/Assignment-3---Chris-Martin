#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Queue {   // Creates class Queue
public:
    Queue();
    ~Queue();

    void push(const T& value);  // Creates push, pop, front, size, empty, and move_to_rear functions
    void pop(); 
    T front() const;
    int size() const;
    bool empty() const;
    void move_to_rear();

private:
    struct Node {   // Creates the struct Node for data
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int count;
};

// Template implementation

template <typename T>
Queue<T>::Queue() : head(nullptr), tail(nullptr), count(0) {}

template <typename T>
Queue<T>::~Queue() {    // Checks if Queue is not empty, if so pop
    while (!empty()) {
        pop();
    }
}

template <typename T>
void Queue<T>::push(const T& value) {   // Checks if node is empty, if so pushes the int head = tail, if not tail->next
    Node* newNode = new Node(value);
    if (empty()) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    count++;
}

template <typename T>
void Queue<T>::pop() {  //Checks if queue is not empty, if so pop the node
    if (!empty()) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count--;
        if (empty()) {
            tail = nullptr;
        }
    }
    else {
        throw underflow_error("Queue is empty. Cannot pop.");
    }
}

template <typename T>
T Queue<T>::front() const { // Checks if queue is not empty if so head->data
    if (!empty()) {
        return head->data;
    }
    throw runtime_error("Queue is empty");
}

template <typename T>
int Queue<T>::size() const {    // Returns size of queueu
    return count;
}

template <typename T>
bool Queue<T>::empty() const {  // If queue is empty, count = 0
    return count == 0;
}

template <typename T>
void Queue<T>::move_to_rear() {     // if count > 1 moves the node to rear
    if (count > 1) {
        T frontValue = front();
        pop();
        push(frontValue);
    }
}
