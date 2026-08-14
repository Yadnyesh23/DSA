// Find the largest element in the array

// Brute force solution ( sort the array using merge sort or quick sort then return the last element)
#include <iostream>
using namespace std;

int largest_element(int arr[], int length){
    for(int pass = 0 ; pass < length - 1; pass++ ){
        for( int j = 0 ; j < length - 1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return arr[length-1];
}

int main() {
    int arr[5] = {5,3,200,200,1};
    int length = sizeof(arr) / sizeof(arr[0]);

    int large = largest_element(arr, length);
    cout << large ;

    return 0;
}
// Time complexity: O(n logn)
// Space complexity: O(1) or O(log n) depending on the sorting algorithm

// -----------------------------------------------//

// Optimal solution ( iterating the array and finding the largest element)
#include <iostream>
using namespace std;

int large_element(int arr[], int length){
    int largest_element = arr[0];

    for(int i = 1 ; i < length ; i++){
        if(arr[i] > largest_element){
            largest_element = arr[i];
        }
    }
    return largest_element;
}

int main() {
    int arr[5] = {5,3,9,2,1};
    int length = sizeof(arr) / sizeof(arr[0]);

    int largest_element = large_element(arr, length);

    cout << largest_element ;

    return 0;
}
// Time complexity: O(n)
// Space complexity: O(1)