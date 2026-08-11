#include<iostream>
using namespace std;

void recursive_bubble_sort(int arr[], int n){
    if (n == 1) return ;
    for(int i = 0 ; i < n - 1; i++){
        if(arr[i] > arr[i+1]){
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
    recursive_bubble_sort(arr, n-1);
}

int main(){
    int arr[9] = {9,8,7,6,5,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    recursive_bubble_sort(arr, n);

    for(int i = 0 ; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}