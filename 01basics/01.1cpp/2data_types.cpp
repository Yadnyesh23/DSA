#include <iostream>
using namespace std;

int main() {

    // int
    // Stores whole numbers
    // Size: 4 bytes
    // Range: approximately -2 billion to +2 billion
    int x = 10;

    // long
    // Used for larger integers than int
    // Size: 4 or 8 bytes (depends on compiler/system)
    long y = 100000L;

    // long long
    // Used for very large integers
    // Size: 8 bytes
    // Range: approximately ±9 × 10^18
    long long z = 1000000000000LL;

    // float
    // Stores decimal numbers
    // Size: 4 bytes
    // Precision: ~6-7 decimal digits
    float f = 2.33212f;

    // double
    // Stores decimal numbers with higher precision
    // Size: 8 bytes
    // Precision: ~15-16 decimal digits
    double d = 23.987826;

    // string
    // Stores a single word (input stops at space)
    string s;
    cin >> s;          // Input: Hello Hi
    cout << s;         // Output: Hello

    // getline()
    // Stores an entire line including spaces
    string line;
    getline(cin >> ws, line); // ws clears leftover whitespace
    cout << line;

    // char
    // Stores a single character
    char ch;
    cin >> ch;
    cout << ch;

    return 0;
}