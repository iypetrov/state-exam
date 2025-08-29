#include <iostream>

using namespace std;

int binary_search(int x, int start, int end, int* arr) {
    if (start > end) {
        return -1;
    }

    int mid = (start + end) / 2;
    if (x == arr[mid]) {
        return mid;
    } else if (x < arr[mid]) {
        return binary_search(x, start, mid - 1, arr);
    } else if (x > arr[mid]) {
        return binary_search(x, mid + 1, end, arr);
    }

    return -1;
}

int main() {
    return 0;
}
