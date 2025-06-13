// There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

// You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

// Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

// Example 1:

// Input: n = 4, connections = [[0,1],[0,2],[1,2]]
// Output: 1
// Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
// Example 2:

// Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
// Output: 2
// Example 3:

// Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
// Output: -1
// Explanation: There are not enough cables.
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> rank;
    vector<int> parent;

    int find(int a)
    {
        if (a == parent[a])
            return a;
        return parent[a] = find(parent[a]); // Path compression
    }

    void Union(int a, int b)
    {
        int a_parent = find(a);
        int b_parent = find(b);

        if (a_parent == b_parent)
            return;

        if (rank[a_parent] > rank[b_parent])
        {
            parent[b_parent] = a_parent;
        }
        else if (rank[a_parent] < rank[b_parent])
        {
            parent[a_parent] = b_parent;
        }
        else
        {
            parent[a_parent] = b_parent;
            rank[b_parent]++;
        }
    }

    int makeConnected(int n, vector<vector<int>> &connections)
    {
        parent.resize(n);
        rank.resize(n, 0);

        int totalEdges = connections.size();
        if (totalEdges < n - 1)
            return -1; // Not enough connections

        for (int i = 0; i < n; i++)
            parent[i] = i;

        int components = n;

        for (auto &conn : connections)
        {
            int a_parent = find(conn[0]);
            int b_parent = find(conn[1]);

            if (a_parent != b_parent)
            {
                Union(a_parent, b_parent);
                components--; // Successfully connected two components
            }
        }

        return components - 1; // We need (components - 1) operations
    }
};

int main()
{
    Solution sol;

    // Example: 6 computers, with these connections
    int n = 6;
    vector<vector<int>> connections = {
        {0, 1}, {0, 2}, {0, 3}, {1, 4}};

    int result = sol.makeConnected(n, connections);

    if (result == -1)
    {
        cout << "Not enough connections to connect all computers.\n";
    }
    else
    {
        cout << "Minimum number of operations to connect all: " << result << "\n";
    }

    return 0;
}
