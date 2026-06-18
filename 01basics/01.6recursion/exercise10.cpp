//Fibonacci number

#include <iostream>
using namespace std;

int fibonacci(int n){
    if(n <= 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}
int main() {
    int n;
    cout << "Enter value of n : " ;
    cin >> n ;
    int val = fibonacci(n);
    cout << "Fibonacci of " << n << " is " << val;

    return 0;
}