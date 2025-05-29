// There exist two undirected trees with n and m nodes, labeled from [0, n - 1] and [0, m - 1], respectively.

// You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree.

// Node u is target to node v if the number of edges on the path from u to v is even. Note that a node is always target to itself.

// Return an array of n integers answer, where answer[i] is the maximum possible number of nodes that are target to node i of the first tree if you had to connect one node from the first tree to another node in the second tree.

// Note that queries are independent from each other. That is, for every query you will remove the added edge before proceeding to the next query.

// Example 1:

// Input: edges1 = [[0,1],[0,2],[2,3],[2,4]], edges2 = [[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]]

// Output: [8,7,7,8,8]

// Explanation:

// For i = 0, connect node 0 from the first tree to node 0 from the second tree.
// For i = 1, connect node 1 from the first tree to node 4 from the second tree.
// For i = 2, connect node 2 from the first tree to node 7 from the second tree.
// For i = 3, connect node 3 from the first tree to node 0 from the second tree.
// For i = 4, connect node 4 from the first tree to node 4 from the second tree.

// Example 2:

// Input: edges1 = [[0,1],[0,2],[0,3],[0,4]], edges2 = [[0,1],[1,2],[2,3]]

// Output: [3,6,6,6,6]

// Explanation:

// For every i, connect node i of the first tree with any node of the second tree.

//  Here mark nodes with zero and one alternatively then if in tree1 nodes at even distance will be of same marking
//  Then for tree2 also find count of zeros and ones and take maximum which will be add to tree1 counts
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void DFS(int curr, unordered_map<int, vector<int>> &adj, int par,
             vector<int> &marks, int &zeroCount, int &oneCount)
    {
        if (marks[curr] == 0)
        {
            zeroCount++;
        }
        else
        {
            oneCount++;
        }

        for (auto &v : adj[curr])
        {
            if (v != par)
            {
                marks[v] = (marks[curr] == 1) ? 0 : 1;
                DFS(v, adj, curr, marks, zeroCount, oneCount);
            }
        }
    }

    unordered_map<int, vector<int>> findAdjM(vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> adj;
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }

    vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2)
    {
        int n1 = edges1.size() + 1;
        int n2 = edges2.size() + 1;
        unordered_map<int, vector<int>> adj1 = findAdjM(edges1);
        unordered_map<int, vector<int>> adj2 = findAdjM(edges2);

        vector<int> marks1(n1, -1), marks2(n2, -1);
        int zeroCount1 = 0, oneCount1 = 0;
        marks1[0] = 0;
        DFS(0, adj1, -1, marks1, zeroCount1, oneCount1);

        int zeroCount2 = 0, oneCount2 = 0;
        marks2[0] = 0;
        DFS(0, adj2, -1, marks2, zeroCount2, oneCount2);

        int maxCountTree2 = max(zeroCount2, oneCount2);
        vector<int> r(n1, 0);
        for (int i = 0; i < n1; i++)
        {
            r[i] = (marks1[i] == 0 ? zeroCount1 : oneCount1) + maxCountTree2;
        }

        return r;
    }
};

int main()
{
    Solution sol;

    // Example trees
    vector<vector<int>> edges1 = {
        {0, 1}, {1, 2}, {1, 3}};
    vector<vector<int>> edges2 = {
        {0, 1}, {0, 2}};

    vector<int> result = sol.maxTargetNodes(edges1, edges2);

    cout << "Result: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
