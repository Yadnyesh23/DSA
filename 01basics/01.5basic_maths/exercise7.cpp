// Check wether number is prime number or not

// Method 1

#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter a number : " ;
    cin >> n ;
    int factors = 0 ;
    for(int i = 1 ; i <= n ; i++){
        if(n % i == 0){
            factors++;
            // cout << i << endl ;
        }
    }
    
    if(factors == 2){
        cout << n << " is a prime number." << endl;
    }else{
        cout << n << " is not a prime number." << endl;
    }
    return 0;
}

// Method 2
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    bool isPrime = true;

    if (n <= 1) {
        isPrime = false;
    } else {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                isPrime = false;
                break;
            }
        }
    }

    if (isPrime)
        cout << n << " is a prime number";
    else
        cout << n << " is not a prime number";

    return 0;
}

// # Why do we use `i * i <= n` for Prime Number Checking?

// ## Naive Approach

// ```cpp
// for(int i = 2; i < n; i++)
// ```

// This loop checks every number from `2` to `n - 1`.

// For `n = 24`, it performs approximately 22 checks.

// Time Complexity: **O(n)**

// ---

// ## Optimized Approach

// ```cpp
// for(int i = 2; i * i <= n; i++)
// ```

// This loop checks only up to `√n`.

// For `n = 24`:

// ```text
// √24 ≈ 4.89
// ```

// So the loop runs for:

// ```text
// i = 2, 3, 4
// ```

// Only 3 checks are required.

// Time Complexity: **O(√n)**

// ---

// ## Why does checking till √n work?

// Factors always occur in pairs.

// Example: `24`

// ```text
// 1 × 24
// 2 × 12
// 3 × 8
// 4 × 6
// ```

// Notice that every factor greater than `√24` has a corresponding factor smaller than `√24`.

// For example:

// ```text
// 12 ↔ 2
// 8  ↔ 3
// 6  ↔ 4
// ```

// Therefore, if a number has any factor greater than `√n`, its paired factor will already be found before `√n`.

// Hence, checking beyond `√n` only repeats information.

// ---

// ## Example: 49

// ```text
// 1 × 49
// 7 × 7
// ```

// ```text
// √49 = 7
// ```

// The loop checks:

// ```text
// 2, 3, 4, 5, 6, 7
// ```

// At `i = 7`:

// ```cpp
// 49 % 7 == 0
// ```

// A factor is found, so 49 is not prime.

// There is no need to check numbers greater than 7 because any factor beyond 7 would have a corresponding factor below 7.

// ---

// ## Important Note About Time Complexity

// For `n = 24`, the loop runs only 5 times (`0, 1, 2, 3, 4`), but we do NOT say the complexity is `O(5)`.

// Big-O describes how the algorithm grows as `n` grows.

// ```text
// n = 24      → √n ≈ 5
// n = 100     → √n = 10
// n = 10000   → √n = 100
// ```

// Since the number of iterations depends on `√n`, the time complexity is:

// ```text
// O(√n)
// ```

// and not `O(5)`.

// ---

// ## Key Takeaway

// * Check divisors only up to `√n`.
// * Factors beyond `√n` are paired with factors below `√n`.
// * This reduces the time complexity from **O(n)** to **O(√n)**.
// * Space Complexity remains **O(1)**.
