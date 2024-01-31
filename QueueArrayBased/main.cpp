#include <iostream>
#include <cassert>

using namespace std;

class Queue {//Circular queue
private:
    int *arr;
    int front, rear;
    int size, capacity;

    int availableSize() { return capacity - size; }

public:
    Queue(int n) : arr(new int[n]), size(0), capacity(n), front(0), rear(0) {}

    Queue() : Queue(1) {};

    void enqueue(int val) {
        assert(availableSize());
        arr[(rear % capacity)] = val, ++rear;
        ++size;
    }

    void deque() {
        assert(size != 0);
        arr[front % capacity] = 0;
        ++front, --size;
    }

    int &Front() {
        return arr[front % capacity];
    }

    bool isEmpty() {
        return size == 0;
    }

    ~Queue() {
        delete[] arr;
    }
};


int main() {
    Queue most(5);
    for (int i = 0; i < 5; ++i) {
        most.enqueue(i);
    }
    most.deque();
    most.deque();
    most.deque();
    most.enqueue(10);
    most.enqueue(20);
    most.enqueue(30);
    most.deque();
    most.deque();
    while (!most.isEmpty()) {
        cout << most.Front();
        most.deque();
    }
    return 0;
}
