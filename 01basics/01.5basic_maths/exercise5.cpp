// Check whether the number is armstrong
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter the number : ";
    cin >> n;

    int originalNum = n;
    int count = 0;

    
    while (n > 0) {
        count++;
        n = n / 10;
    }

    n = originalNum;   

    int sum = 0;

    while (n > 0) {
        int digit = n % 10;
        sum += pow(digit, count);
        n = n / 10;
    }

    cout << "Count : " << count << endl;
    cout << "Sum : " << sum << endl;

    if (sum == originalNum) {
        cout << "Armstrong Number";
    } else {
        cout << "Not an Armstrong Number";
    }

    return 0;
}