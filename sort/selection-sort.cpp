#include <iostream>

void swap(int& a, int& b){
    a = a + b;
    b = a - b;
    a = a - b;
}

void selection_sort(int* arr, int len) {
    for(int i = 0; i < len; i++) {
        int min = i;
        for(int j = i + 1; j < len; j++) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }

        swap(arr[i], arr[min]);
    }
}

int main(){
    return 0;
}
