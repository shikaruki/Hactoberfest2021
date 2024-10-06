#include <iostream>
#include <string>
#include <vector>

using namespace std;

int min(int a, int b) {
    return (a < b) ? a : b;
}

string longestPalindrome(const string &mainString) {
    if (mainString.empty()) return "";

    // Transform the string to insert boundaries
    string T = "^#"; // Starting with sentinel characters
    for (char c : mainString) {
        T += c;
        T += '#';
    }
    T += '$'; // Ending with a sentinel

    int n = T.size();
    vector<int> P(n, 0); // Array to store lengths of palindromes
    int center = 0, right = 0;
    
    for (int i = 1; i < n - 1; i++) {
        int mirror = 2 * center - i; // Calculate the mirror index

        if (right > i) {
            P[i] = min(right - i, P[mirror]); // Use the mirror value if within bounds
        }

        // Expand around center i
        while (T[i + P[i] + 1] == T[i - P[i] - 1]) {
            P[i]++;
        }

        // Update center and right boundary if needed
        if (i + P[i] > right) {
            center = i;
            right = i + P[i];
        }
    }

    // Find the maximum length and its center
    int maxLen = 0, centerIndex = 0;
    for (int i = 1; i < n - 1; i++) {
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }

    // Extract the longest palindromic substring
    int start = (centerIndex - maxLen) / 2; // Get the starting index in the original string
    return mainString.substr(start, maxLen);
}

int main() {
    string mainString;
    cout << "Enter String: ";
    cin >> mainString;

    string palindrome = longestPalindrome(mainString);
    cout << "Longest palindrome is: " << palindrome << endl;

    return 0;
}
