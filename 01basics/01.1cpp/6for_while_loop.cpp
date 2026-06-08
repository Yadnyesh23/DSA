
#include <iostream>
using namespace std;

int main() {
    
    // For loop
    for(int i = 0 ; i <= 10 ; i++){
        cout << i << endl ;
    }
    
    // While Loop
    int i = 0 ;
    while(i <= 5){
        cout << i << endl ;
        i++;
    }
    
    // Do-While Loop
    int i = 2
    do{
        cout << i << endl;
        i++;
    };
    while(i <=1);
    
    //Difference between Do-while and while loop
    //In while loop condition is checked first than code is executed
    //In Do-While loop code executed once than conditions is checked
    
    return 0;
}