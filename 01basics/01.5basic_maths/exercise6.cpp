// Find all divisors
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter the number : ";
    cin >> n;
    
    cout << "Divisors of " << n << endl;
    for(int i = 1 ; i <= n ; i++){
        if(n % i == 0){
            cout << i << endl;
        }
    }

    return 0;
}