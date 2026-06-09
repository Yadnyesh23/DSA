// Pattern
// A B C D E 
// A B C D 
// A B C 
// A B 
// A 


#include<iostream>

using namespace std;

int main(){
    int rows;
    cout << "Enter no. of rows : ";
    cin >> rows ;
    
    for(int i = 0; i < rows ; i++){
        for(char ch = 'A'; ch <= 'A' + (rows - i - 1)  ; ch++){
           cout << ch << " ";
        }
        cout << endl ;
    }
    
    return 0;
}