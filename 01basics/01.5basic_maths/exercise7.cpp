// Check wether number is prime number or not

// Method 1

#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter a number : " ;
    cin >> n ;
    int factors = 0 ;
    for(int i = 1 ; i <= n ; i++){
        if(n % i == 0){
            factors++;
            // cout << i << endl ;
        }
    }
    
    if(factors == 2){
        cout << n << " is a prime number." << endl;
    }else{
        cout << n << " is not a prime number." << endl;
    }
    return 0;
}

// Method 2
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    bool isPrime = true;

    if (n <= 1) {
        isPrime = false;
    } else {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                isPrime = false;
                break;
            }
        }
    }

    if (isPrime)
        cout << n << " is a prime number";
    else
        cout << n << " is not a prime number";

    return 0;
}