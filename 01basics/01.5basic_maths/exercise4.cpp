// Find GCD
#include <iostream>
using namespace std;

int main() {
    int n1, n2;
    cout << "Enter the valueof n1 : " << endl ;
    cin >> n1;
    cout << "Enter the valueof n2 : " << endl;
    cin >> n2;
    int min;
    if(n1 < n2){
        min = n1;
    }else{
        min = n2;
    }
    
    int gcd = 1 ;
    for(int i = min ; i >= 1 ; i--){
        if(n1 % i == 0 && n2 % i == 0){
            gcd = i;
            break;
        }
        else{
            gcd = 0;
        }
    }
    
    cout << "GCD : " << gcd << endl;

    return 0;
}