#include <iostream>
using namespace std;

// Function to calculate 3 raised to the power of n using a loop
int powerOfThree(int n) {
    int result = 1;  // Initializing result as 1 (3^0)
    for (int i = 1; i <= n; ++i) {
        result *= 3;  // Multiply result by 3 in each iteration
    }
    return result;
}

int main() {
    int n;
    cout << "Enter the power: ";
    cin >> n;

    int result = powerOfThree(n);
    cout << "3 raised to the power of " << n << " is: " << result << endl;

    return 0;
}
