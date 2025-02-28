// Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

// A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        int m = str1.size(), n = str2.size();
        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (str1[i - 1] == str2[j - 1])
                    f[i][j] = f[i - 1][j - 1] + 1;
                else
                    f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
        int i = m, j = n;
        string ans;
        while (i || j)
        {
            if (i == 0)
                ans += str2[--j];
            else if (j == 0)
                ans += str1[--i];
            else
            {
                if (f[i][j] == f[i - 1][j])
                    ans += str1[--i];
                else if (f[i][j] == f[i][j - 1])
                    ans += str2[--j];
                else
                    ans += str1[--i], --j;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution solution;
    string str1 = "abac";
    string str2 = "cab";
    cout << "Shortest Common Supersequence: " << solution.shortestCommonSupersequence(str1, str2) << endl;
    return 0;
}
