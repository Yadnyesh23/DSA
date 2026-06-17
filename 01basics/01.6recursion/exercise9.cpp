// check whether the string is palindrome - using recursion

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool palindrome(string name,int i, int size){
    if (i >= size / 2) return true;
    if(name[i] != name[size-i-1]) return false;
    
    return palindrome(name, i+1, size);
}

int main() {
    string name;
    cout << "Enter the string : ";
    cin >> name ;
    int size = name.length();
    
    for (int i = 0; i < size; i++) {
        name[i] = tolower(name[i]);
    }
    
    bool isPalindrome = palindrome(name,0, size);
    
    if(isPalindrome == true){
        cout << "String is palindrome";
    }
    else{
        cout << "String is not palindrome";
    }
    
   
   return 0;
}