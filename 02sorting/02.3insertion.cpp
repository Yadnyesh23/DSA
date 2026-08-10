#include <iostream>
using namespace std;

void insertion_sort(int arr[5], int length){
    for(int i = 1; i < length ; i++){
        int key = arr[i];
        int j = i - 1;
        
        while(j >= 0 && arr[j] > key ){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    
    
}
int main() {
    
    int arr[5] = {5,3,2,1,4};
    
    int length = sizeof(arr)/sizeof(arr[0]);
    
    insertion_sort(arr, length);
    
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}