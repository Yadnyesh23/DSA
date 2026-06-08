#include <iostream>
#include <string>
using namespace std;

int main() {

    // =========================
    // 1-D ARRAY
    // =========================

    int arr1[5];

    // Input 5 elements
    cin >> arr1[0] >> arr1[1] >> arr1[2] >> arr1[3] >> arr1[4];

    // Print all elements
    cout << arr1[0] << " "
         << arr1[1] << " "
         << arr1[2] << " "
         << arr1[3] << " "
         << arr1[4] << endl;

    // Direct access using index
    cout << "Last element: " << arr1[4] << endl;


    // =========================
    // 2-D ARRAY (Matrix)
    // =========================

    int arr2[2][5];

    // Input first row
    cin >> arr2[0][0] >> arr2[0][1] >> arr2[0][2]
        >> arr2[0][3] >> arr2[0][4];

    // Input second row
    cin >> arr2[1][0] >> arr2[1][1] >> arr2[1][2]
        >> arr2[1][3] >> arr2[1][4];

    // Print first row
    cout << arr2[0][0] << " "
         << arr2[0][1] << " "
         << arr2[0][2] << " "
         << arr2[0][3] << " "
         << arr2[0][4] << endl;

    // Print second row
    cout << arr2[1][0] << " "
         << arr2[1][1] << " "
         << arr2[1][2] << " "
         << arr2[1][3] << " "
         << arr2[1][4] << endl;

    // Direct access
    cout << "Element at row 0, col 4: "
         << arr2[0][4] << endl;


    // =========================
    // STRING
    // =========================

    string name = "Yadnyesh";

    // Strings are stored as a sequence of characters
    cout << name[2] << endl;   // Output: d

    int length = name.length();
    cout << "Length: " << length << endl;


    return 0;
}