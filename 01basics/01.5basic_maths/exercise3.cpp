// Check whether the number is palindrome or not.

#include <iostream>
using namespace std;

int main() {
   int n;
   cout << "Enter the number : ";
   cin >> n;
   int originalNum = n;
   cout << "Original number : " << n << endl ;
   int reverseNum = 0;
   
   while(n > 0){
       int lastNum = n % 10;
       reverseNum = (reverseNum * 10) + lastNum ;
       n = n /10;
   }
   
   cout << "Reverse number : " << reverseNum << endl;
   
   if(originalNum == reverseNum){
       cout << "Number is palindrome.";
   }
   else{
       cout << "Number is not palindrome.";
   }
   
   
    return 0;
}