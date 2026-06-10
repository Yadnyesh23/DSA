// Pattern 
// E
// D E
// C D E
// B C D E
// A B C D E

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of rows: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        char ch = 'A' + (n - 1 - i);

        for (char j = ch; j <= 'A' + (n - 1); j++) {
            cout << j << " ";
        }

        cout << endl;
    }

    return 0;
}