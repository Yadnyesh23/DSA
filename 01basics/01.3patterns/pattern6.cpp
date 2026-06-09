// Pattern 
// 1 2 3 4 5
// 1 2 3 4
// 1 2 3 
// 1 2 
// 1 


#include<iostream>
using namespace std;

int main(){
    int rows, cols;
    cout << "Enter number of rows : " ;
    cin >> rows ;
    cout << "Enter number of columns : " ;
    cin >> cols ;

    for(int i = 1 ; i <=rows ; i++){
        for(int j = 1 ; j <= cols - i + 1 ; j++){
            cout << j << " ";
        }
        cout << endl ;
    }
    return 0;
}