#include <iostream>
using namespace std;

// Function to calculate the nth Fibonacci number using recursion
int fibonacci(int n) {
    if (n <= 1) {
        return n;  // Base case: F(0) = 0, F(1) = 1
    }
    return fibonacci(n - 1) + fibonacci(n - 2);  // Recursive case
}

// Function to print the Fibonacci series up to the nth term
void printFibonacciSeries(int n) {
    for (int i = 0; i < n; ++i) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;

    cout << "Fibonacci series: ";
    printFibonacciSeries(n);

    return 0;
}
