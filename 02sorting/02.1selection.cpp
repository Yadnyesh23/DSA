#include<iostream>
using namespace std;

void selection_sort(int arr[], int size){
    for(int i = 0 ; i < size - 1; i++){
        int smallest = i;
        for(int j = i ; j <= size - 1 ; j++){
            if(arr[j] < arr[smallest]){
                smallest = j;
            }
        }
        int temp = arr[smallest];
        arr[smallest] = arr[i];
        arr[i] = temp;
    }
    cout<< "Sorted array : " ;
    for(int i = 0 ; i < size ; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int size;
    cout << "Enter size of array : ";
    cin >> size;
    
    int arr[size];
    cout << "Enter elements of array : " << endl;
    for(int i = 0 ; i < size ; i++){
        cin >> arr[i];
    }
    
    cout << "Unsorted array : ";
    for(int i = 0 ; i < size ; i++){
        cout <<  arr[i] << " ";
    }
    cout << endl;
    
    selection_sort(arr, size);
    return 0;
}