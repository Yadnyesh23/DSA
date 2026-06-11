//Print name N times

#include <iostream>
using namespace std;

int count = 0 ;

int print(int i , int n){
    if(i > n ) return 0;
    cout << "Yadnyesh" << endl ;
    i++ ;
    print(i,n);
    return 0;
}
int main() {
    int i = 1;
    int n;
    cout << "Enter n value : " << endl;
    cin >> n;
    print(i,n);

    return 0;
}