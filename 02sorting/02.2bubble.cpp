#include <iostream>
using namespace std;

void bubble_sort(int arr[], int length) {
    for (int pass = 0; pass < length - 1; pass++) {
        for (int i = 0; i < length - 1 - pass; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }

    cout << "Sorted array : ";
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[5] = {5, 4, 9, 2, 1};

    int length = sizeof(arr) / sizeof(arr[0]);

    cout << "Length of array : " << length << endl;

    cout << "Unsorted array : ";
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    bubble_sort(arr, length);

    return 0;
}