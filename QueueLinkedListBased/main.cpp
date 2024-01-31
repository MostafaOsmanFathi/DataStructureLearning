#include <iostream>

using namespace std;

class Queue {
private:
    struct Node {
        Node *next = nullptr;
        int data;

        Node(int data) : data(data) {

        }
    };

public:
    Node *Front = nullptr;
    Node *rear = nullptr;

    void enqueue(int val) {
        if (Front == nullptr) {
            Front = rear = new Node(val);
        }
        rear->next = new Node(val);
        rear = rear->next;
    }

    void deque() {
        Node *rmNode = Front;
        Front = Front->next;
        delete rmNode;
    }

    int &front() {
        return Front->data;
    }

    bool isEmpty() { return Front == nullptr; }

    ~Queue() {
        while (!isEmpty()) { deque(); }
    }
};

int main() {


    return 0;
}
