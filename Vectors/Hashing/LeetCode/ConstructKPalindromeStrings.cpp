// Given a string s and an integer k, return true if you can use all the characters in s to construct k palindrome strings or false otherwise.
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    bool canConstruct(string s, int k)
    {
        // If the string has fewer characters than k, it's impossible to construct k palindromes
        if (s.size() < k)
            return false;

        // Frequency array to count occurrences of each character
        vector<int> freq(26, 0);

        // Count character frequencies
        for (auto ch : s)
        {
            freq[ch - 'a']++;
        }

        // Count the number of characters with odd frequencies
        int oddCount = 0;
        for (auto count : freq)
        {
            if (count % 2 != 0)
            {
                oddCount++;
            }
        }

        // A valid construction is possible if oddCount <= k
        return oddCount <= k;
    }
};

int main()
{
    Solution solution;

    // Test cases
    string s1 = "annabelle";
    int k1 = 2;

    string s2 = "leetcode";
    int k2 = 3;

    string s3 = "true";
    int k3 = 4;

    // Output results
    cout << boolalpha;                                                // To print true/false instead of 1/0
    cout << "Test Case 1: " << solution.canConstruct(s1, k1) << '\n'; // Expected: true
    cout << "Test Case 2: " << solution.canConstruct(s2, k2) << '\n'; // Expected: false
    cout << "Test Case 3: " << solution.canConstruct(s3, k3) << '\n'; // Expected: true

    return 0;
}
