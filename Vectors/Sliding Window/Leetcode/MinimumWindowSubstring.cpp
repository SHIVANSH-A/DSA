// Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
// Example 2:

// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.
// Example 3:

// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.

// Constraints:

// m == s.length
// n == t.length
// 1 <= m, n <= 105
// s and t consist of uppercase and lowercase English letters.
#include <iostream>
#include <string>
#include <map>
#include <climits>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.size();
        map<char, int> mpp;

        // Count frequency of characters in t
        for (auto &ch : t)
        {
            mpp[ch]++;
        }

        int validCount = t.size();
        int i = 0, j = 0;
        int minSize = INT_MAX;
        int start_idx = 0;

        while (j < n)
        {
            char ch = s[j];

            // Only count if this char is part of t
            if (mpp[ch] > 0)
            {
                validCount--;
            }

            // Decrement map always (for tracking extra chars)
            mpp[ch]--;

            // Try to shrink the window
            while (validCount == 0)
            {
                int currSize = j - i + 1;

                if (currSize < minSize)
                {
                    minSize = currSize;
                    start_idx = i;
                }

                // Shrink from left
                mpp[s[i]]++;

                // If character is required, increase validCount
                if (mpp[s[i]] > 0)
                {
                    validCount++;
                }

                i++;
            }

            j++;
        }

        return (minSize == INT_MAX) ? "" : s.substr(start_idx, minSize);
    }
};

int main()
{
    Solution sol;

    string s = "ADOBECODEBANC";
    string t = "ABC";

    string result = sol.minWindow(s, t);
    cout << "Minimum window substring: " << result << endl;

    return 0;
}
