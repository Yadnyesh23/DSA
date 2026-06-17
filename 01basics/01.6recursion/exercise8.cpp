// reverse array using recursion
#include <iostream>
using namespace std;

// 2 Pointers - Left and right
void reverseArray(int arr[], int l, int r, int size){
    if(l >= r) {
        cout << " Reversed array :- " ;
     for(int i = 0 ; i < size; i++ )   {
         cout << " " << arr[i] << " ";
     }
     return;
    }
    int temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;
    reverseArray(arr, l+1, r-1, size);
    return;
}

int main() {
    int size;
    cout << "Enter the size of array : ";
    cin >> size ;
    int arr[size];
   
   // Input the array elements
    for(int i = 0 ; i < size ; i++){
    cout << "Enter element at position " << i  << " : ";
    cin >> arr[i] ;
    }
  //Print array elements
    cout << "Original array :- ";
    for(int i = 0 ; i < size ; i++){
    cout << " " << arr[i] << " "  ;
    }
    cout << endl ;
    
    reverseArray(arr, 0, size-1, size);
   
   return 0;
}


// 1 Pointer 
void reverseArray(int arr[],int p, int size){
    if(p >= size-p-1) {
        cout << " Reversed array :- " ;
     for(int i = 0 ; i < size; i++ )   {
         cout << " " << arr[i] << " ";
     }
     return;
    }
    int temp = arr[p];
    arr[p] = arr[size-p-1];
    arr[size-p-1] = temp;
    reverseArray(arr,p+1, size);
    return;
}

int main() {
    int size;
    cout << "Enter the size of array : ";
    cin >> size ;
    int arr[size];
   
   // Input the array elements
    for(int i = 0 ; i < size ; i++){
    cout << "Enter element at position " << i  << " : ";
    cin >> arr[i] ;
    }
  //Print array elements
    cout << "Original array :- ";
    for(int i = 0 ; i < size ; i++){
    cout << " " << arr[i] << " "  ;
    }
    cout << endl ;
    
    reverseArray(arr, 0, size);
   
   return 0;
}