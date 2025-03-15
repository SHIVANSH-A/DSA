// You are given a string s of lowercase English letters and a 2D integer array shifts where shifts[i] = [starti, endi, directioni]. For every i, shift the characters in s from the index starti to the index endi (inclusive) forward if directioni = 1, or shift the characters backward if directioni = 0.

// Shifting a character forward means replacing it with the next letter in the alphabet (wrapping around so that 'z' becomes 'a'). Similarly, shifting a character backward means replacing it with the previous letter in the alphabet (wrapping around so that 'a' becomes 'z').

// Return the final string after all such shifts to s are applied.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    Solution sol;
    string str = "abc";
    vector<vector<int>> shifts = {{0, 1, 1}, {1, 2, 1}, {0, 2, 0}};
    cout << sol.shiftingLetters(str, shifts) << endl;
    return 0;
}
class Solution
{
public:
    string shiftingLetters(string str, vector<vector<int>> &shifts)
    {
        int n = str.size();
        vector<int> s(n, 0);
        for (auto q : shifts)
        {
            int l = q[0];
            int r = q[1];
            int x = q[2];
            if (x == 1)
            {
                s[l] += 1;
                if (r + 1 < n)
                    s[r + 1] -= 1;
            }
            else
            {
                s[l] += -1;
                if (r + 1 < n)
                    s[r + 1] -= -1;
            }
        }

        for (int i = 1; i < n; i++)
        {
            s[i] += s[i - 1];
        }
        for (int i = 0; i < n; i++)
        {
            // If number is greater than 25
            int shift = s[i] % 26;
            // For handling negative number
            if (shift < 0)
                shift += 26;
            // For handling circular assignment
            str[i] = (((str[i] - 'a') + shift) % 26) + 'a';
        }
        return str;
    }
};