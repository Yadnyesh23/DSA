// Move all zeros to right by maintaining the order
#include <iostream>
using namespace std;
void move_zeros(int arr[], int length){
    for(int i = 0 ; i < length -1; i++){
        for(int j = 0 ; j < length; j++){
            if(arr[i] == 0  && arr[j] != 0){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
            }
        }
    }
    for(int i = 0 ; i<length ; i++) {
        cout << arr[i] << " ";
    }
}
int main() {
    int arr[5]  = {0, 1, 0, 3, 12};
    int length = sizeof(arr)/sizeof(arr[0]);

    move_zeros(arr, length);
    return 0;
}