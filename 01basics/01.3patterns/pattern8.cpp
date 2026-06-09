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
        for(int j = 1 ; j <= cols - i -1 ; j++){
            cout << " ";
        }
        //Stars
        for(int j = 0 ; j < (2 * i) + 1 ; j++ ){
            cout << "*";
        }
        cout << endl;
    }
    return 0;