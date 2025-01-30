// You are given a positive integer n representing the number of nodes in an undirected graph. The nodes are labeled from 1 to n.

// You are also given a 2D integer array edges, where edges[i] = [ai, bi] indicates that there is a bidirectional edge between nodes ai and bi. Notice that the given graph may be disconnected.

// Divide the nodes of the graph into m groups (1-indexed) such that:

// Each node in the graph belongs to exactly one group.
// For every pair of nodes in the graph that are connected by an edge [ai, bi], if ai belongs to the group with index x, and bi belongs to the group with index y, then |y - x| = 1.
// Return the maximum number of groups (i.e., maximum m) into which you can divide the nodes. Return -1 if it is impossible to group the nodes with the given conditions.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    Solution sol;

    // Example 1
    int n1 = 6;
    vector<vector<int>> edges1 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}};
    cout << "Result for Example 1: " << sol.magnificentSets(n1, edges1) << endl;

    // Example 2
    int n2 = 4;
    vector<vector<int>> edges2 = {{1, 2}, {2, 3}, {3, 4}, {4, 1}};
    cout << "Result for Example 2: " << sol.magnificentSets(n2, edges2) << endl;

    // Example 3 (Disconnected graph)
    int n3 = 5;
    vector<vector<int>> edges3 = {{1, 2}, {3, 4}};
    cout << "Result for Example 3: " << sol.magnificentSets(n3, edges3) << endl;

    return 0;
}
class Solution
{
public:
    int magnificentSets(int n, vector<vector<int>> &edges)
    {
        vector<int> g[n];
        for (auto &e : edges)
        {
            int a = e[0] - 1, b = e[1] - 1;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<int> d(n);
        for (int i = 0; i < n; ++i)
        {
            queue<int> q{{i}};
            vector<int> dist(n);
            dist[i] = 1;
            int mx = 1;
            int root = i;
            while (q.size())
            {
                int a = q.front();
                q.pop();
                root = min(root, a);
                for (int b : g[a])
                {
                    if (dist[b] == 0)
                    {
                        dist[b] = dist[a] + 1;
                        mx = max(mx, dist[b]);
                        q.push(b);
                    }
                    else if (abs(dist[b] - dist[a]) != 1)
                    {
                        return -1;
                    }
                }
            }
            d[root] = max(d[root], mx);
        }
        return accumulate(d.begin(), d.end(), 0);
    }
};