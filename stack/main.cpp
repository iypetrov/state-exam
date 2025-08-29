#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node(int val) : data(val), prev(nullptr) {}
};

class Stack {
private:
    Node* top;
public:
    Stack() : top(nullptr) {}

    ~Stack() {
        while(top) {
            pop();
        }
    }

    void print() {
        Node* curr = top;
        while(curr) {
            cout << curr->data << endl;
            curr = curr->prev;
        }
    }

    bool empty() {
        if(top == nullptr) {
            return true;
        }
        return false;
    }

    void push(int x) {
        Node* curr = new Node(x);
        if (top == nullptr) {
            top = curr;
            return;
        }

        curr->prev = top;
        top = curr;
    }

    void pop() {
        if (top == nullptr) {
            return;
        }

        Node* curr = top;
        top = top->prev;
        delete curr;
    }

    int peek() {
        if (top == nullptr) {
            return -1;      
        }
        return top->data;
    }
}; 

int main() {
    return 0;
}
