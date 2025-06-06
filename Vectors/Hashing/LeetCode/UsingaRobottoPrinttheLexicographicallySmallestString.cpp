// You are given a string s and a robot that currently holds an empty string t. Apply one of the following operations until s and t are both empty:

// Remove the first character of a string s and give it to the robot. The robot will append this character to the string t.
// Remove the last character of a string t and give it to the robot. The robot will write this character on paper.
// Return the lexicographically smallest string that can be written on the paper.

// Example 1:

// Input: s = "zza"
// Output: "azz"
// Explanation: Let p denote the written string.
// Initially p="", s="zza", t="".
// Perform first operation three times p="", s="", t="zza".
// Perform second operation three times p="azz", s="", t="".
// Example 2:

// Input: s = "bac"
// Output: "abc"
// Explanation: Let p denote the written string.
// Perform first operation twice p="", s="c", t="ba".
// Perform second operation twice p="ab", s="c", t="".
// Perform first operation p="ab", s="", t="c".
// Perform second operation p="abc", s="", t="".
// Example 3:

// Input: s = "bdda"
// Output: "addb"
// Explanation: Let p denote the written string.
// Initially p="", s="bdda", t="".
// Perform first operation four times p="", s="", t="bdda".
// Perform second operation four times p="addb", s="", t="".

// Constraints:

// 1 <= s.length <= 105
// s consists of only English lowercase letters.

// Logic - Precompute the letters which are min in right of each char
//         If t has char min than its right min then write else move forward to get min char
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string robotWithString(string s)
    {
        int n = s.size();
        string t = "";
        string r = "";
        vector<char> minCharToRight(n);
        minCharToRight[n - 1] = s.back();

        // Precompute the minimum character to the right of each index
        for (int i = n - 2; i >= 0; i--)
        {
            if (s[i] < minCharToRight[i + 1])
            {
                minCharToRight[i] = s[i];
            }
            else
            {
                minCharToRight[i] = minCharToRight[i + 1];
            }
        }

        for (int i = 0; i < n; i++)
        {
            t += s[i];
            char minChar = (i + 1 < n) ? minCharToRight[i + 1] : minCharToRight[i];

            while (!t.empty() && t.back() <= minChar)
            {
                r += t.back();
                t.pop_back();
            }
        }

        while (!t.empty())
        {
            r += t.back();
            t.pop_back();
        }

        return r;
    }
};

int main()
{
    Solution sol;

    // Test cases
    string input1 = "zza";
    string input2 = "bac";
    string input3 = "bdda";

    cout << "Input: " << input1 << " -> Output: " << sol.robotWithString(input1) << endl;
    cout << "Input: " << input2 << " -> Output: " << sol.robotWithString(input2) << endl;
    cout << "Input: " << input3 << " -> Output: " << sol.robotWithString(input3) << endl;

    return 0;
}
