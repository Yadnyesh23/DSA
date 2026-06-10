// Pattern 
// * * * * * * * * * * 
// * * * *     * * * * 
// * * *         * * * 
// * *             * * 
// *                 * 
// *                 * 
// * *             * * 
// * * *         * * * 
// * * * *     * * * * 
// * * * * * * * * * * 

#include <iostream>
using namespace std;

int main() {
    int rows;
    cout << "Enter number of rows: ";
    cin >> rows;
    
    int space = 0;
    //Upper
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < rows - i; j++){
            cout << "* ";
        }
        for(int j = 0 ; j < space ; j++){
            cout << "  ";
        }
        
        for(int j = 0 ; j < rows - i; j++){
            cout << "* ";
        }
        space += 2;
        cout << endl;
    }
    space = 8;
    // Lower
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j <= i  ; j++){
            cout << "* ";
        }
        for(int j = 0 ; j < space ; j++){
            cout << "  ";
        }
        for(int j = 0 ; j <= i  ; j++){
            cout << "* ";
        }
        space -= 2;
        cout << endl;
    }

    return 0;
}