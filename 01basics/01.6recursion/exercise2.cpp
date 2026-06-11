// Print linearly from 1 to n
#include <iostream>
using namespace std;


void printNum(int i , int n){
    if(i > n) return;
    cout << i << endl ;
    i++;
    printNum(i,n);
}
int main() {
    int i = 1;
    int n;
    cout << "Enter n value : " ;
    cin >> n;
    
    printNum(i,n);

    return 0;
}