// Pattern
// A 
// B B 
// C C C  
// D D D D 
// E E E E E 


#include<iostream>

using namespace std;

int main(){
    int rows;
    cout << "Enter no. of rows : ";
    cin >> rows ;
    
    for(int i = 0 ; i < rows ; i++){
    char character = 'A' + i;
        for(int j = 0 ; j <= i; j++){
            cout << character << " ";
        }
        cout << endl;
    }
    
    return 0;
}