// Check whether array is sorted

#include <iostream>
using namespace std;

int is_array_sorted(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        if(arr[i] < arr[i - 1]) {
            return 0;
        }
    }

    return 1;
}


int main(){
    int arr[4] = {4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    int result = is_array_sorted(arr, n);
    if(result ==  1){
        cout << "Array is sorted";
    }else if(result == 0){
        cout << "Array is not sorted";
    }

    return 0;
}

// Time Complexity = O(n)
// Space Complexity = O(1)