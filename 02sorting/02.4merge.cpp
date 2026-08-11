#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int low, int mid,  int high){
    int left = low;
    int right = mid + 1;
    vector<int> temp;
   while(left <= mid && right <= high){
    if(arr[left] <= arr[right]){
        temp.push_back(arr[left]);
        left++;
    }
    else{
        temp.push_back(arr[right]);
        right++;
    }
   }

   
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = 0; i < temp.size(); i++) {
        arr[low + i] = temp[i];
    }
}

void merge_sort(int arr[], int low, int high){
    if(low == high){
        return;
    }
    int mid = (low+high)/2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid+1, high);
    merge(arr, low, mid, high);

}
int main() {
    int arr[5] = {5,2,3,1,4};
    int length = sizeof(arr)/sizeof(arr[0]);
    int low = 0 ; 
    int high = length - 1;

    merge_sort(arr, low, high);

    for(int i = 0 ; i < length; i++){
        cout << arr[i] << " ";
    }
    

    return 0;
}