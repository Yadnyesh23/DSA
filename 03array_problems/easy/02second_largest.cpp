#include <iostream>
using namespace std;

// Brute force solution ( sort the array using merge sort or quick sort then return the last element)
#include <iostream>
using namespace std;

void second_largest(int arr[], int length){
    for(int pass = 0 ; pass < length - 1; pass++ ){
        for( int j = 0 ; j < length - 1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    int largest = arr[length-1];
    for(int i = length - 2 ; i >= 0 ; i--){
        if(arr[i] != largest){
            cout << "Second largest : " << arr[i];
            break;
        }
    }
}

int main() {
    int arr[5] = {5,3,20,200,1};
    int length = sizeof(arr) / sizeof(arr[0]);

    second_largest(arr, length);
    

    return 0;
}
// Time complexity: O(n logn)
// Space complexity: O(1) or O(log n) depending on the sorting algorithm

// -----------------------------------------------//

//  Better (Find the largest in first pass and then find the 2nd largest and not equal to largest)
#include <iostream>
using namespace std;

int second_largest(int arr[], int n){

    int largest = arr[0];
    int second_largest = -1;

    for(int i = 0 ; i < n - 1; i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
    }

    for(int i = 0 ; i < n ; i++){
        if(arr[i] > second_largest & arr[i] != largest){
            second_largest = arr[i];
        }
    }
    return second_largest;
}

int main(){
    int arr[5] = {5,3,7,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    int second_largest_element = second_largest(arr, n);
    cout << "Second Largest : " << largest_element ; 

    return 0;
}
// Time complexity: O(2n)
// Space complexity: O(1)
// -----------------------------------------------//

// Optimal solution ( storing largest and second largest in a single pass)
#include <iostream>
using namespace std;

int second_largest(int arr[], int n){
    int largest = arr[0];
    int second_largest = -1;
    for(int i = 1 ; i < n ; i++){
        if(arr[i] > largest){
            second_largest = largest;
            largest = arr[i];
        }
        else if(arr[i] > second_largest & arr[i] != largest){
            second_largest = arr[i];
        }
    }
    return second_largest;
}

int main(){
    int arr[9] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);

    int second_largest_element = second_largest(arr, n);
    cout << "Second Largest : " << second_largest_element ; 

    return 0;
}
// Time complexity: O(n)
// Space complexity: O(1)