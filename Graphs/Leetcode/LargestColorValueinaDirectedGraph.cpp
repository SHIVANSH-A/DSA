// There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.

// You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj.

// A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path.

// Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.

// Example 1:

// Input: colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
// Output: 3
// Explanation: The path 0 -> 2 -> 3 -> 4 contains 3 nodes that are colored "a" (red in the above image).
// Example 2:

// Input: colors = "a", edges = [[0,0]]
// Output: -1
// Explanation: There is a cycle from 0 to 0.
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int largestPathValue(string colors, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> adj;
        int n = colors.size();
        vector<vector<int>> colorTrack(n, vector<int>(26, 0));
        vector<int> inDegree(n, 0);
        int visited = 0;
        int count = 0;

        // Build graph and in-degree list
        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }

        queue<int> q;
        // Initialize zero in-degree nodes
        for (int i = 0; i < n; ++i)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
                colorTrack[i][colors[i] - 'a'] = 1;
            }
        }

        // Topological sort + dynamic color count
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            visited++;
            count = max(count, colorTrack[u][colors[u] - 'a']);

            for (int &v : adj[u])
            {
                for (int i = 0; i < 26; ++i)
                {
                    colorTrack[v][i] = max(colorTrack[v][i], colorTrack[u][i] + ((colors[v] - 'a') == i));
                }
                inDegree[v]--;
                if (inDegree[v] == 0)
                    q.push(v);
            }
        }

        return (visited != n) ? -1 : count;
    }
};

// Main function with test case
int main()
{
    Solution sol;

    // Test Case: DAG with paths where 'a' appears 3 times
    string colors = "abaca"; // node 0:'a', 1:'b', 2:'a', 3:'c', 4:'a'
    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {2, 3},
        {3, 4}};

    int result = sol.largestPathValue(colors, edges);
    cout << "Maximum number of same color in any path: " << result << endl;

    return 0;
}
