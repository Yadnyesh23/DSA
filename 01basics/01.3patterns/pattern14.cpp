// Pattern
// A 
// A B 
// A B C 
// A B C D 
// A B C D E 


#include<iostream>

using namespace std;

int main(){
    int rows;
    cout << "Enter no. of rows : ";
    cin >> rows ;
    
    for(int i = 0; i < rows ; i++){
        for(char ch = 'A'; ch <= 'A'+ i ; ch++){
           cout << ch << " ";
        }
        cout << endl ;
    }
    
    return 0;
}