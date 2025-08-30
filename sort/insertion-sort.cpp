#include <iostream>

void swap(int& a, int& b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

void insertion_sort(int* arr, int len) {
    for(int i = 1; i < len; i++) {
        for(int k = i; k > 0; k--) {
            if (arr[k] >= arr[k - 1]) {
                break;
            }
            swap(arr[k], arr[k - 1]);
        }
    }
}

int main() {
    return 0;
}
