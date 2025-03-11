// Given a string s consisting only of characters a, b and c.

// Return the number of substrings containing at least one occurrence of all these characters a, b and c.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    Solution solution;
    string s;
    cout << "Enter string: ";
    cin >> s;
    int result = solution.numberOfSubstrings(s);
    cout << "Number of substrings containing all characters: " << result << endl;
    return 0;
}

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        unordered_map<char, int> mpp;

        int i = 0, j = 0;
        long long count = 0;

        while (j < s.size())
        {
            char ch = s[j];
            mpp[ch]++;

            while (mpp.size() == 3)
            {
                char ch = s[i];
                count += s.size() - j;

                mpp[ch]--;
                if (mpp[ch] == 0)
                    mpp.erase(ch);

                i++;
            }
            j++;
        }
        return count;
    }
};