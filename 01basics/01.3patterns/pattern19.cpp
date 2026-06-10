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
    
    //Upper
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < rows - i; j++){
            cout << "* ";
        }
        for(int j = 0 ; j < i ; j++){
            cout << "  ";
        }
        for(int j = 0 ; j < i ; j++){
            cout << "  ";
        }
        for(int j = 0 ; j < rows - i; j++){
            cout << "* ";
        }
        cout << endl;
    }
    //Lower
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j <= i  ; j++){
            cout << "* ";
        }
        for(int j = 0 ; j < rows - i - 1; j++ ){
            cout << "  ";
        }
        for(int j = 0 ; j < rows - i - 1; j++ ){
            cout << "  ";
        }
        for(int j = 0 ; j <= i  ; j++){
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}