#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* back;

public:
    Queue() : front(nullptr), back(nullptr) {}
    ~Queue() {
        while(front) {
            pop();
        }
    }

    bool empty() {
        if(front == nullptr) {
            return true;
        }
        return false;
    }

    void print() {
        Node* curr = front;
        while(curr) {
            cout << curr->data << endl;
            curr = curr->next;
        }
    }

    void push(int x) {
        Node* curr = new Node(x);
        if (front == nullptr) {
            front = curr;
            back = curr;
            return;
        }

        back->next = curr;
        back = curr;
    }

    void pop() {
        if (front == nullptr) {
            return;
        }

        Node* curr = front;
        front = front->next;
        if (front == nullptr) {
            back = nullptr;
        }
        delete curr;
    }

    int peek() {
        if (front == nullptr) {
            return -1;
        }
        return front->data;
    }
};

int main() {
    return 0;
}
