// Pattern 
// *                 * 
// * *             * * 
// * * *         * * * 
// * * * *     * * * * 
// * * * * * * * * * * 
// * * * *     * * * * 
// * * *         * * * 
// * *             * * 
// *                 * 

#include <iostream>
using namespace std;

int main() {
    int rows;
    cout << "Enter number of rows: ";
    cin >> rows;
    int space = (2 * rows) - 2 ;
    // Upper
   for(int i = 0 ; i < rows ; i++){
       for(int j = 0 ; j <= i ; j++){
           cout << "* " ; 
       }
       for(int j = 0 ; j < space ; j++){
           cout << "  ";
       }
      for(int j = 0 ; j <=i ; j++){
          cout << "* " ; 
      }
       space -= 2;
       cout << endl;
   }
   // Lower
   for(int i = 1 ; i < rows ; i++){
   space = (2 * i);
       for(int j = 0 ; j < rows - i; j++){
           cout << "* ";
       }
       for(int j = 0 ; j < space ; j++){
           cout << "  ";
       }
       for(int j = 0 ; j < rows - i; j++){
           cout << "* ";
       }
       cout << endl;
   }

    return 0;
}