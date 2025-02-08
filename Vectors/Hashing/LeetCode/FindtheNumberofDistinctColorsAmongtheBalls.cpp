// ou are given an integer limit and a 2D array queries of size n x 2.

// There are limit + 1 balls with distinct labels in the range [0, limit]. Initially, all balls are uncolored. For every query in queries that is of the form [x, y], you mark ball x with the color y. After each query, you need to find the number of distinct colors among the balls.

// Return an array result of length n, where result[i] denotes the number of distinct colors after ith query.

// Note that when answering a query, lack of a color will not be considered as a color.
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> g;
        unordered_map<int, int> cnt;
        vector<int> ans;
        for (auto& q : queries) {
            int x = q[0], y = q[1];
            cnt[y]++;
            if (g.contains(x) && --cnt[g[x]] == 0) {
                cnt.erase(g[x]);
            }
            g[x] = y;
            ans.push_back(cnt.size());
        }
        return ans;
    }
};
int main() {
    Solution sol;
    int limit = 10; // Example limit
    vector<vector<int>> queries = {
        {1, 2},
        {2, 3},
        {1, 3},
        {4, 5}
    };

    vector<int> result = sol.queryResults(limit, queries);

    // Print the results
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
