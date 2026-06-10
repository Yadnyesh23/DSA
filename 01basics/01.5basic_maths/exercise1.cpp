// Count number of digits in number give by user

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