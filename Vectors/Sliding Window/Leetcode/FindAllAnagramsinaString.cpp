// Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

// Example 1:

// Input: s = "cbaebabacd", p = "abc"
// Output: [0,6]
// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".
// Example 2:

// Input: s = "abab", p = "ab"
// Output: [0,1,2]
// Explanation:
// The substring with start index = 0 is "ab", which is an anagram of "ab".
// The substring with start index = 1 is "ba", which is an anagram of "ab".
// The substring with start index = 2 is "ab", which is an anagram of "ab".

// Constraints:

// 1 <= s.length, p.length <= 3 * 104
// s and p consist of lowercase English letters.
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    bool allZero(vector<int> &freq)
    {
        for (int i : freq)
        {
            if (i != 0)
                return false;
        }
        return true;
    }

    vector<int> findAnagrams(string txt, string pat)
    {
        vector<int> freq(26, 0); // Frequency of characters in pat
        vector<int> r;           // Result to store indices

        int n = txt.size();
        int k = pat.size();

        if (k > n)
            return r;

        // Fill freq with frequency of characters in pat
        for (int i = 0; i < k; i++)
        {
            freq[pat[i] - 'a']++;
        }

        int i = 0, j = 0;
        while (j < n)
        {
            freq[txt[j] - 'a']--; // include txt[j] in the window

            // When window size equals size of pat
            if (j - i + 1 == k)
            {
                if (allZero(freq))
                    r.push_back(i);   // Check for anagram
                freq[txt[i] - 'a']++; // remove txt[i] from window
                i++;
            }

            j++;
        }

        return r;
    }
};

// Main function to test the code
int main()
{
    string txt = "cbaebabacd";
    string pat = "abc";

    Solution sol;
    vector<int> result = sol.findAnagrams(txt, pat);

    cout << "Anagram indices: ";
    for (int index : result)
    {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}
