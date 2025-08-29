#include <cstdlib>
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void print(Node* node) {
    if(node == nullptr) {
        return;
    }

    print(node->left);
    cout << node << " " << node->data << endl;
    print(node->right);
}

Node* findMin(Node* node) {
    if (node == nullptr) {
        return nullptr;
    }

    Node* curr = node;
    while (curr->left) {
        curr = curr->left;
    }
    return curr;
}

Node* findMax(Node* node) {
    if (node == nullptr) {
        return nullptr;
    }

    Node* curr = node;
    while (curr->right) {
        curr = curr->right;
    }
    return curr;
}

class BinaryTree {
    private:
        Node* root;

    public:
        BinaryTree() : root(nullptr) {}
        ~BinaryTree() { 
            clear(root); 
        }

        Node* getRoot() {
            return root;
        }

        void clear(Node* node) {
            if (!node) return;
            clear(node->left);
            clear(node->right);
            delete node;
        }

        void insert(int x) {
            if(root == nullptr) {
                root = new Node(x);
                return;
            }

            Node* node = root;
            while(true) {
                if(x < node->data) {
                    if(node->left) {
                        node = node->left;
                    } else {
                        node->left = new Node(x);
                        break;
                    }
                } else {
                    if(node->right) {
                        node = node->right;
                    } else {
                        node->right = new Node(x);
                        break;
                    }
                }
            }
        }

        Node* search(int x) {
            Node* curr = root;
            while (curr) {
                if (x == curr->data) {
                    return curr;
                } else if (x < curr->data) {
                    curr = curr->left;
                } else {
                    curr = curr->right;
                }
            }
            return nullptr;
        }

        Node* remove(Node* root, int x) {
            if (root == nullptr) {
                return nullptr;
            }

            if (x < root->data) {
                root->left = remove(root->left, x);
            } else if (x > root->data) {
                root->right = remove(root->right, x);
            } else {
                // Case 1: No children
                if (root->left == nullptr && root->right == nullptr) {
                    delete root;
                    return nullptr;
                }
                // Case 2: One child
                else if (root->left == nullptr) {
                    Node* temp = root->right;
                    delete root;
                    return temp;
                }
                else if (root->right == nullptr) {
                    Node* temp = root->left;
                    delete root;
                    return temp;
                }
                // Case 3: Two children
                else {
                    Node* successor = findMin(root->right);
                    root->data = successor->data;
                    root->right = remove(root->right, successor->data);
                }
            }
            return root;
        }
};

int main() {
    return 0;
}
