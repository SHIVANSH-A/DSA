// Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a == c and b == d), or (a == d and b == c) - that is, one domino can be rotated to be equal to another domino.

// Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        int cnt[100]{}; // 2-digit encoding, max value 9*10+9 = 99
        int ans = 0;
        for (auto &e : dominoes)
        {
            // Encode the pair in a normalized way (smaller number first)
            int x = e[0] < e[1] ? e[0] * 10 + e[1] : e[1] * 10 + e[0];
            ans += cnt[x]++;
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> dominoes = {
        {1, 2}, {2, 1}, {3, 4}, {5, 6}};

    Solution sol;
    int result = sol.numEquivDominoPairs(dominoes);
    cout << "Number of equivalent domino pairs: " << result << endl;

    return 0;
}
