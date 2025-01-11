// You are given a 0-indexed string array words.

// Let's define a boolean function isPrefixAndSuffix that takes two strings, str1 and str2:

// isPrefixAndSuffix(str1, str2) returns true if str1 is both a
// prefix
//  and a
// suffix
//  of str2, and false otherwise.
// For example, isPrefixAndSuffix("aba", "ababa") is true because "aba" is a prefix of "ababa" and also a suffix, but isPrefixAndSuffix("abc", "abcd") is false.

// Return an integer denoting the number of index pairs (i, j) such that i < j, and isPrefixAndSuffix(words[i], words[j]) is true.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int countPrefixSuffixPairs(vector<string> &words)
    {
        int cnt = 0;

        // Iterate through all pairs of words
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words.size(); j++)
            {
                // Avoid self-comparison and only consider unique pairs (i < j)
                if (i != j && i < j)
                {
                    if (isPrefixAndSuffix(words[i], words[j]))
                    {
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }

private:
    // Helper function to check if str1 is both a prefix and a suffix of str2
    bool isPrefixAndSuffix(const string &str1, const string &str2)
    {
        int len1 = str1.length();
        int len2 = str2.length();

        // Check if str1 can be a prefix and suffix of str2
        if (len1 > len2)
            return false;

        // Check prefix
        if (str1 != str2.substr(0, len1))
            return false;

        // Check suffix
        if (str1 != str2.substr(len2 - len1, len1))
            return false;

        return true;
    }
};

int main()
{
    Solution solution;

    // Test cases
    vector<string> words1 = {"abc", "ab", "bc", "abcabc", "abc"};
    vector<string> words2 = {"aaa", "aa", "a", "aaaa"};
    vector<string> words3 = {"cat", "dog", "c", "ca", "catdog"};

    // Call the function and output results
    cout << "Test Case 1: " << solution.countPrefixSuffixPairs(words1) << '\n'; // Expected: 2
    cout << "Test Case 2: " << solution.countPrefixSuffixPairs(words2) << '\n'; // Expected: 4
    cout << "Test Case 3: " << solution.countPrefixSuffixPairs(words3) << '\n'; // Expected: 0

    return 0;
}
