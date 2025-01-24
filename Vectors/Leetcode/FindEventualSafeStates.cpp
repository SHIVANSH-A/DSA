// There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

// A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

// Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.
enum class State
{
    kInit,
    kVisiting,
    kVisited
};

class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        vector<int> ans;
        vector<State> states(graph.size());

        for (int i = 0; i < graph.size(); ++i)
            if (!hasCycle(graph, i, states))
                ans.push_back(i);

        return ans;
    }

private:
    bool hasCycle(const vector<vector<int>> &graph, int u,
                  vector<State> &states)
    {
        if (states[u] == State::kVisiting)
            return true;
        if (states[u] == State::kVisited)
            return false;

        states[u] = State::kVisiting;
        for (const int v : graph[u])
            if (hasCycle(graph, v, states))
                return true;
        states[u] = State::kVisited;

        return false;
    }
};
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    Solution solution;

    // Example graph: adjacency list representation
    vector<vector<int>> graph = {
        {1, 2},  // Node 0 points to nodes 1 and 2
        {2, 3},  // Node 1 points to nodes 2 and 3
        {5},     // Node 2 points to node 5
        {0},     // Node 3 points to node 0 (cycle)
        {5},     // Node 4 points to node 5
        {},      // Node 5 has no outgoing edges
        {4, 5}}; // Node 6 points to nodes 4 and 5

    // Call eventualSafeNodes to find all safe nodes
    vector<int> safeNodes = solution.eventualSafeNodes(graph);

    // Print the result
    cout << "Safe nodes: ";
    for (int node : safeNodes)
        cout << node << " ";
    cout << endl;

    return 0;
}
