// Print sum of first n numbers
#include <iostream>
using namespace std;

// Functional Way

int summation(int n){
    if(n == 0 || n == 1) return 1;
    return n + summation(n-1);
    
}

int main() {
    int n ;
    cout << "Enter the value of n : " ;
    cin >> n ;
   
    int sum = summation(n);
    cout << "Sum : " << sum ;
    return 0;
}

// Parameterised way

#include <iostream>
using namespace std;

void summation(int i, int sum){
   if(i < 1) {
       cout<<sum;
       return ;
   }
   summation(i-1, sum+i);
}

int main() {
    int n ;
    cout << "Enter the value of n : " ;
    cin >> n ;
    int sum = 0 ; 
   summation(n, sum);
    return 0;
}