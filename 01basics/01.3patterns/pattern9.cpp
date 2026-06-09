// Pattern
//         * 
//       * * * 
//     * * * * * 
//   * * * * * * * 
// * * * * * * * * *
// * * * * * * * * *
//   * * * * * * * 
//     * * * * * 
//       * * * 
//         * 

#include <iostream>
using namespace std;
int main() {
    // Write C++ code here
   int rows = 5;
   int cols = 5;
   
   for(int i = 0 ; i < rows ; i++){
        //Space
        for(int j = 1 ; j <= cols - i -1 ; j++){
            cout << "  ";
        }
        //Stars
        for(int j = 0 ; j < (2 * i) + 1 ; j++ ){
            cout << "* ";
        }
        cout << endl;
    }
   for(int i = 0 ; i < rows ; i++){
        //Space
        for(int j = 0  ; j < i ; j++){
            cout << "  ";
        }
        //Stars
        for(int j = 0 ; j < (2 * cols ) - ((2 * i )+ 1); j++ ){
            cout << "* ";
        }
        
        //Space
        for(int j = 0  ; j < i ; j++){
            cout << "  ";
        }
        cout << endl;
    }

    return 0;
}