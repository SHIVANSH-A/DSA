// A company is organizing a meeting and has a list of n employees, waiting to be invited. They have arranged for a large circular table, capable of seating any number of employees.

// The employees are numbered from 0 to n - 1. Each employee has a favorite person and they will attend the meeting only if they can sit next to their favorite person at the table. The favorite person of an employee is not themself.

// Given a 0-indexed integer array favorite, where favorite[i] denotes the favorite person of the ith employee, return the maximum number of employees that can be invited to the meeting.
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    Solution solution;
    
    // Test case: favorite vector
    vector<int> favorite = {2, 2, 3, 4, 1};

    // Calculate the maximum invitations
    int result = solution.maximumInvitations(favorite);

    // Print the result
    cout << "Maximum number of invitations: " << result << endl;

    return 0;
}

enum class State { kInit, kVisiting, kVisited };

class Solution {
 public:
  int maximumInvitations(vector<int>& favorite) {
    const int n = favorite.size();
    int sumComponentsLength = 0; 
    vector<vector<int>> graph(n);
    vector<int> inDegrees(n);
    vector<int> maxChainLength(n, 1);
    queue<int> q;

    
    for (int i = 0; i < n; ++i) {
      graph[i].push_back(favorite[i]);
      ++inDegrees[favorite[i]];
    }

    
    for (int i = 0; i < n; ++i)
      if (inDegrees[i] == 0)
        q.push(i);

    while (!q.empty()) {
      const int u = q.front();
      q.pop();
      for (const int v : graph[u]) {
        if (--inDegrees[v] == 0)
          q.push(v);
        maxChainLength[v] = max(maxChainLength[v], 1 + maxChainLength[u]);
      }
    }

    for (int i = 0; i < n; ++i)
      if (favorite[favorite[i]] == i)
       
        sumComponentsLength += maxChainLength[i] + maxChainLength[favorite[i]];

    int maxCycleLength = 0; 
    vector<int> parent(n, -1);
    vector<bool> seen(n);
    vector<State> states(n);

    for (int i = 0; i < n; ++i)
      if (!seen[i])
        findCycle(graph, i, parent, seen, states, maxCycleLength);

    return max(sumComponentsLength / 2, maxCycleLength);
  }

 private:
  void findCycle(const vector<vector<int>>& graph, int u, vector<int>& parent,
                 vector<bool>& seen, vector<State>& states,
                 int& maxCycleLength) {
    seen[u] = true;
    states[u] = State::kVisiting;

    for (const int v : graph[u]) {
      if (!seen[v]) {
        parent[v] = u;
        findCycle(graph, v, parent, seen, states, maxCycleLength);
      } else if (states[v] == State::kVisiting) {
        int curr = u;
        int cycleLength = 1;
        while (curr != v) {
          curr = parent[curr];
          ++cycleLength;
        }
        maxCycleLength = max(maxCycleLength, cycleLength);
      }
    }

    states[u] = State::kVisited;
  }
};