// Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

// Find the leftmost occurrence of the substring part and remove it from s.
// Return s after removing all occurrences of part.

// A substring is a contiguous sequence of characters in a string.
#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        while (s.find(part) != -1)
        { // Alternative: while (s.find(part) != string::npos)
            s.erase(s.find(part), part.size());
        }
        return s;
    }
};

int main()
{
    Solution solution;

    // Test cases
    string s1 = "daabcbaabcbc";
    string part1 = "abc";
    cout << "Result 1: " << solution.removeOccurrences(s1, part1) << endl; // Expected output: "dab"

    string s2 = "axxxxyyyybxxxxyyyyb";
    string part2 = "bxxxxyyyy";
    cout << "Result 2: " << solution.removeOccurrences(s2, part2) << endl; // Expected output: ""

    string s3 = "abcdef";
    string part3 = "xyz";
    cout << "Result 3: " << solution.removeOccurrences(s3, part3) << endl; // Expected output: "abcdef"

    string s4 = "aaaabaaa";
    string part4 = "aa";
    cout << "Result 4: " << solution.removeOccurrences(s4, part4) << endl; // Expected output: ""

    return 0;
}