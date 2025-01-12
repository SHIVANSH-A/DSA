//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // Function to reorganize the string such that no two adjacent characters are the same
    string reorganizeString(string s)
    {
        vector<int> counts(26, 0); // Counts for each character in the alphabet

        // Calculate the counts for each character in the string
        for (char c : s)
        {
            ++counts[c - 'a'];
        }

        // Find the maximum occurrence of a character
        int maxCount = *max_element(counts.begin(), counts.end());
        int n = s.size();

        // If the maximum count is more than half the length of the string, reorganization is not possible
        if (maxCount > (n + 1) / 2)
            return "";

        // Pairing count of characters with their corresponding alphabet index
        vector<pair<int, int>> charCounts;
        for (int i = 0; i < 26; ++i)
        {
            if (counts[i])
            {
                charCounts.push_back({counts[i], i});
            }
        }

        // Sort the character counts in ascending order
        sort(charCounts.begin(), charCounts.end());

        // Then reverse to have descending order
        reverse(charCounts.begin(), charCounts.end());

        // Prepare the result string with the same length as the input
        string result = s;
        int idx = 0; // Index to keep track of placement in result string

        // Loop through sorted character counts and distribute characters across the result string
        for (auto &entry : charCounts)
        {
            int count = entry.first, alphabetIndex = entry.second;
            while (count--)
            {
                // Place the character at the index, then skip one place for the next character
                result[idx] = 'a' + alphabetIndex;
                idx += 2; // Move to the next position skipping one

                // If we reach or pass the end of the string, start placing characters at the first odd index
                if (idx >= n)
                    idx = 1;
            }
        }

        // Return the reorganized string
        return result;
    }
};

int main()
{
    Solution solution;

    // Test cases
    string test1 = "aab";
    string test2 = "aaab";
    string test3 = "vvvlo";

    cout << "Input: " << test1 << " -> Output: " << solution.reorganizeString(test1) << endl;
    cout << "Input: " << test2 << " -> Output: " << solution.reorganizeString(test2) << endl;
    cout << "Input: " << test3 << " -> Output: " << solution.reorganizeString(test3) << endl;

    return 0;
}
