// Print linearly from N to 1

#include <iostream>
using namespace std;



void printNum(int i){
    if(i < 1) return;
    cout << i << endl ;
    i--;
    printNum(i);
}
int main() {
    
    int n;
    cout << "Enter n value : " ;
    cin >> n;
    int i = n;
    printNum(i);
    

    return 0;
}