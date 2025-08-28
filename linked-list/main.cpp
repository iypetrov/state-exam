// single linked list
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    bool empty() {
        if (head == nullptr && tail == nullptr) {
            return true;
        }
        return false;
    }

    void print() {
        Node* curr = head;
        while(curr) {
            cout << curr->data << endl;
            curr = curr->next;
        }
    }

    int get(int pos) {
        Node* curr = head;
        int result = -1;
        int i = 0;
        while(curr) {
            if (i == pos) {
                result = curr->data;
                break;
            }
            curr = curr->next;
            i++;
        }
        return result;
    }

    void insert(int x, int pos) {
        if (head == nullptr) { 
            return;
        }

        if (pos == 0) {
            push_front(x);
            return;
        }

        Node* curr = head;
        Node* prev = nullptr;
        for (int i = 0; i < pos; i++) {
            if (curr != nullptr) {
                prev = curr;
                curr = curr->next;
            }
        }
        prev->next = new Node(x, curr);
        if (tail == prev) {
            tail = prev->next;
        }
    }

    void push_front(int x) {
        Node* node = new Node(x);
        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            node->next = head;
            head = node;
        }
    }

    void push_back(int x) {
        Node* node = new Node(x);
        if (tail == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    void pop_front() {
        if (head == nullptr) {
            return;
        }  
        
        Node* curr = head;
        curr = head->next;
        delete head;
        head = curr;
    }

    void pop_back() {
        if (head == nullptr) {
            return;
        }  

        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }
        
        Node* curr = head;
        while (curr->next != tail) {
            curr = curr->next;
        }
        delete tail;
        tail = curr;
        tail->next = nullptr;
    }
};

int main() {
    return 0;
}
