// Pattern
// 1             1 
// 1 2         2 1 
// 1 2 3     3 2 1 
// 1 2 3 4 4 3 2 1 


#include<iostream>

using namespace std;

int main(){
    int rows, cols;
    cout << "Enter no. of rows : ";
    cin >> rows;
    // cout << "Enter no. of cols : ";
    // cin >> cols;
    int space = 2 * ( rows - 1 );
    
    for(int i = 1 ; i <= rows ; i++){
        for(int j = 1 ; j <= i ; j++){
            cout << j << " ";
        }
        
        for(int j = 0 ; j < space; j++){
            cout << "* ";
        }
        
        for(int j = i ; j >= 1 ; j--){
            cout << j << " ";
        }
         space -= 2 ;
        cout << endl;
    }
    
    return 0;
}// Pattern
// 1             1 
// 1 2         2 1 
// 1 2 3     3 2 1 
// 1 2 3 4 4 3 2 1 


#include<iostream>

using namespace std;

int main(){
    int rows, cols;
    cout << "Enter no. of rows : ";
    cin >> rows;
    // cout << "Enter no. of cols : ";
    // cin >> cols;
    int space = 2 * ( rows - 1 );
    
    for(int i = 1 ; i <= rows ; i++){
        for(int j = 1 ; j <= i ; j++){
            cout << j << " ";
        }
        
        for(int j = 0 ; j < space; j++){
            cout << "  ";
        }
        
        for(int j = i ; j >= 1 ; j--){
            cout << j << " ";
        }
         space -= 2 ;
        cout << endl;
    }
    
    return 0;
}