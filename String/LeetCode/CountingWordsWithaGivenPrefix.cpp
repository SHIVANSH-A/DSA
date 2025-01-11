// You are given an array of strings words and a string pref.

// Return the number of strings in words that contain pref as a prefix.

// A prefix of a string s is any leading contiguous substring of s.
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int prefixCount(vector<string> &words, string pref)
    {
        int cnt = 0;             // Initialize counter
        int len = pref.length(); // Length of the prefix
        for (auto i : words)
        {
            // Check if the prefix matches the start of the current word
            if (i.substr(0, len) == pref)
                cnt++;
        }
        return cnt;
    }
};

int main()
{
    Solution solution;

    // Test cases
    vector<string> words1 = {"apple", "app", "apricot", "banana", "apply"};
    string pref1 = "app";

    vector<string> words2 = {"dog", "cat", "camel", "canary"};
    string pref2 = "ca";

    vector<string> words3 = {"test", "testing", "tester", "tent"};
    string pref3 = "tes";

    // Output results
    cout << "Test Case 1: " << solution.prefixCount(words1, pref1) << '\n'; // Expected: 3
    cout << "Test Case 2: " << solution.prefixCount(words2, pref2) << '\n'; // Expected: 3
    cout << "Test Case 3: " << solution.prefixCount(words3, pref3) << '\n'; // Expected: 3

    return 0;
}
