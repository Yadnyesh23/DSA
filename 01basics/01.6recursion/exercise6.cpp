// Print sum of first n numbers

#include <iostream>
using namespace std;

int summation(int i, int n, int sum){
    if(i > n) return sum;
    sum += i;
    i++;
    
    return summation(i,n,sum);
}
int main() {
    int n;
    int i = 0;
    int sum = 0;
    cout << "Enter the value of n : ";
    cin >> n;
    sum = summation(i, n, sum);
    cout << "Summation of fist "<< n << " numbers is " << sum ;
    return 0;
}