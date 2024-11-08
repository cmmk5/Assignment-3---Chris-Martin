#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Queue {
public:
    Queue();
    ~Queue();

    void push(const T& value);
    void pop();
    T front() const;
    int size() const;
    bool empty() const;
    void move_to_rear();

private:
    struct Node {
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
Queue<T>::~Queue() {
    while (!empty()) {
        pop();
    }
}

template <typename T>
void Queue<T>::push(const T& value) {
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
void Queue<T>::pop() {
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
T Queue<T>::front() const {
    if (!empty()) {
        return head->data;
    }
    throw runtime_error("Queue is empty");
}

template <typename T>
int Queue<T>::size() const {
    return count;
}

template <typename T>
bool Queue<T>::empty() const {
    return count == 0;
}

template <typename T>
void Queue<T>::move_to_rear() {
    if (count > 1) {
        T frontValue = front();
        pop();
        push(frontValue);
    }
}
