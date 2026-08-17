// array :- {2, 7, 11, 15} . target = 9 
// return the index of the elements whose sum is equal to the target element.

#include <iostream>
using namespace std;

void two_sum(int arr[], int length, int target, int &i, int &j) {

    for(int x = 0; x < length - 1; x++) {
        for(int y = x + 1; y < length; y++) {

            int sum = arr[x] + arr[y];

            if(sum == target) {
                i = x;
                j = y;
                return;
            }
        }
    }

    i = -1;
    j = -1;
}

int main() {

    int arr[4] = {2, 7, 11, 15};

    int length = sizeof(arr) / sizeof(arr[0]);

    int target = 9;

    int i, j;

    two_sum(arr, length, target, i, j);

    cout << "First index : " << i << endl;
    cout << "Second index : " << j << endl;

    return 0;
}