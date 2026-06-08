#include <iostream>
using namespace std;

/*
========================================
1. VOID FUNCTION
========================================
- Performs a task.
- Does NOT return any value.
*/

void printName() {
    cout << "Hey, Yadnyesh!" << endl;
}

/*
========================================
2. RETURN FUNCTION
========================================
- Returns a value.
- Return type should match the returned value.
*/

int printSum(int a, int b) {
    return a + b;
}

/*
========================================
3. PARAMETERIZED FUNCTION
========================================
- Takes input (parameters) to perform work.
*/

void greet(string name) {
    cout << "Hey, " << name << "!" << endl;
}

/*
========================================
4. NON-PARAMETERIZED FUNCTION
========================================
- Does not take any input.
*/

void welcome() {
    cout << "Welcome to DSA!" << endl;
}

/*
========================================
PASS BY VALUE
========================================
- A COPY of the variable is passed.
- Changes inside the function do NOT
  affect the original variable.
*/

void passByValue(int num) {
    cout << "Inside Function: " << num << endl;

    num += 5;
    cout << "After +5: " << num << endl;

    num += 5;
    cout << "After +10: " << num << endl;
}

/*
========================================
PASS BY REFERENCE
========================================
- Original variable is passed.
- Changes inside the function DO affect
  the original variable.

'&' indicates reference.
*/

void passByReference(int &num) {
    cout << "Inside Function: " << num << endl;

    num += 5;
    cout << "After +5: " << num << endl;

    num += 5;
    cout << "After +10: " << num << endl;
}

/*
========================================
ARRAYS IN FUNCTIONS
========================================
Arrays are effectively passed by reference.

Any modification inside the function
affects the original array.
*/

void updateArray(int arr[], int size) {
    arr[0] = 100;
}

int main() {

    /*
    ========================================
    VOID FUNCTION
    ========================================
    */

    printName();

    /*
    ========================================
    PARAMETERIZED FUNCTION
    ========================================
    */

    greet("Yadnyesh");

    /*
    ========================================
    NON-PARAMETERIZED FUNCTION
    ========================================
    */

    welcome();

    /*
    ========================================
    RETURN FUNCTION
    ========================================
    */

    int a = 2;
    int b = 3;

    int sum = printSum(a, b);

    cout << "Sum = " << sum << endl;

    /*
    ========================================
    PASS BY VALUE
    ========================================
    */

    int num1 = 10;

    passByValue(num1);

    cout << "Outside Function: "
         << num1 << endl;

    // Output: 10
    // Original value remains unchanged

    /*
    ========================================
    PASS BY REFERENCE
    ========================================
    */

    int num2 = 10;

    passByReference(num2);

    cout << "Outside Function: "
         << num2 << endl;

    // Output: 20
    // Original value gets modified

    /*
    ========================================
    ARRAYS
    ========================================
    */

    int arr[5] = {1, 2, 3, 4, 5};

    updateArray(arr, 5);

    cout << "First Element: "
         << arr[0] << endl;

    // Output: 100

    return 0;
}