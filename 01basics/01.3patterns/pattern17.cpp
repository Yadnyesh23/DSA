// Pattern 
//         A 
//       A B A 
//     A B C B A 
//   A B C D C B A 
// A B C D E D C B A 


#include <iostream>
using namespace std;

int main() {
    int rows ;
    cout << "Enter no. of rows : ";
    cin >> rows ;
    
    
    for(int i = 0 ; i < rows ; i++){
        // space 
        for(int j = 0 ; j < rows - i -1 ; j++){
            cout << "  "  ;
        }
        char ch = 'A';
        int breakpoint = ((2*i) + 1)/2;
        
        for(int j = 0 ; j < (2 * i) + 1 ; j++){
            cout << ch << " ";
            if(j < breakpoint) ch++ ;
            else ch--;
            
        }
        cout << endl ;
    }

    return 0;
}