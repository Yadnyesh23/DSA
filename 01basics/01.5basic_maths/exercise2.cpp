// reverse the number given by user
#include <iostream>
using namespace std;

int main() {
   int n;
   cout << "Enter the number : ";
   cin >> n;
   cout << "Original number : " << n << endl ;
   int reverseNum = 0;
   
   while(n > 0){
       int lastNum = n % 10;
       reverseNum = (reverseNum * 10) + lastNum ;
       n = n /10;
   }
   
   cout << "Reverse number : " << reverseNum;
   
   
    return 0;
}