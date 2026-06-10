// Count number of digits in number give by user

// Method 1
#include <iostream>
using namespace std;

int main() {
   int n;
   cout << "Enter the number : ";
   cin >> n;
   int count=0;

   while(n>0){
       int digit = n % 10;
       count++;
       n = n / 10;
   }
   cout << "Count : " << count ;
   
    return 0;
}

//Method 2
#include<bits/stdc++.h>

int count(int n){
    int count = (int)(log10(n) + 1);
    return count;
}