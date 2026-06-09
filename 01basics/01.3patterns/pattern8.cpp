// Pattern
// * * * * * * * * *
//   * * * * * * * 
//     * * * * * 
//       * * * 
//         * 


#include<iostream>
using namespace std;

int main(){
    int rows, cols;
    cout << "Enter number of rows : " ;
    cin >> rows ;
    cout << "Enter number of columns : " ;
    cin >> cols ;

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