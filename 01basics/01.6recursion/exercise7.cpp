// Print factorial of first n numbers

#include <iostream>
using namespace std;

int factorial(int n){
   if(n == 0 || n == 1) return 1;
   return n * factorial(n-1);
}

int main() {
    int n ;
    cout << "Enter the value of n : " ;
    cin >> n ;
    
    int fact = factorial(n) ;
    cout << "factorial of " << n << " is : " << fact;
    
}