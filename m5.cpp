#include <iostream>
#include <vector>
using namespace std;

// Function to perform wildcard matching
bool isMatch(string s, string p) {
    int m = s.length();
    int n = p.length();

    // DP table to store the result of subproblems
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

    // Base case: empty string matches with empty pattern
    dp[0][0] = true;

    // If the pattern starts with '*' we can match it with an empty string
    for (int j = 1; j <= n; ++j) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 1];
        }
    }

    // Fill the DP table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                // If characters match or there's a '?' wildcard
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                // If there's a '*' wildcard, it can match zero or more characters
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
        }
    }

    // The result is stored in dp[m][n], where m is the length of s and n is the length of p
    return dp[m][n];
}

int main() {
    string s, p;
    cout << "Enter the string: ";
    cin >> s;
    cout << "Enter the pattern: ";
    cin >> p;

    if (isMatch(s, p)) {
        cout << "The string matches the pattern!" << endl;
    } else {
        cout << "The string does not match the pattern!" << endl;
    }

    return 0;
}
