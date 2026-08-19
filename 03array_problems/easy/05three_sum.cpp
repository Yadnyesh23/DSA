// Return the triplet whose sum is equal to zero
// For e.g. [-1,0,1,2,-1,-4]
// Output :- [ [-1 0 1 ], [-1 2 -1 ], [0 1 -1 ] ]

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> three_sum(int arr[], int length){
    vector<vector<int>>  mainArray = {};

    for(int i = 0 ; i < length - 2; i++){
        for(int j = i + 1 ; j < length - 1; j++){
            for(int k = j + 1; k < length; k++){
                int sum = arr[i] + arr[j] + arr[k];
                if(sum ==  0){
                     vector<int> subArray1 = {arr[i], arr[j], arr[k]};
                     mainArray.push_back(subArray1);
                }
            }
        }
    }
    return mainArray;
}

int main() {
    int arr[6]={-1,0,1,2,-1,-4};
    int length = sizeof(arr)/sizeof(arr[0]);

    vector<vector<int>> result = three_sum(arr, length);
    cout << "[";
    for (vector<int> triplet : result) {
        cout << " [";
    for (int x : triplet) {
        cout << x << " ";
    }
    cout << "],";
}
cout << "]";
    

    return 0;
}