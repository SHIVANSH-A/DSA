// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course ai first if you want to take course bi.

// For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.
// Prerequisites can also be indirect. If course a is a prerequisite of course b, and course b is a prerequisite of course c, then course a is a prerequisite of course c.

// You are also given an array queries where queries[j] = [uj, vj]. For the jth query, you should answer whether course uj is a prerequisite of course vj or not.

// Return a boolean array answer, where answer[j] is the answer to the jth query.
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int numCourses = 4;
  vector<vector<int>> prerequisites = {{0, 1}, {1, 2}, {2, 3}};
  vector<vector<int>> queries = {{0, 3}, {1, 3}, {3, 0}, {2, 0}};

  Solution solution;
  vector<bool> result = solution.checkIfPrerequisite(numCourses, prerequisites, queries);

  cout << "Results of queries:" << endl;
  for (bool res : result) {
    cout << (res ? "true" : "false") << endl;
  }

  return 0;
}  
class Solution {
 public:
  vector<bool> checkIfPrerequisite(int numCourses,
                                   vector<vector<int>>& prerequisites,
                                   vector<vector<int>>& queries) {
    vector<bool> ans;
    vector<vector<int>> graph(numCourses);
   
    vector<vector<bool>> isPrerequisite(numCourses, vector<bool>(numCourses));

    for (const vector<int>& prerequisite : prerequisites) {
      const int u = prerequisite[0];
      const int v = prerequisite[1];
      graph[u].push_back(v);
    }

    
    for (int i = 0; i < numCourses; ++i)
      dfs(graph, i, isPrerequisite[i]);

    for (const vector<int>& query : queries) {
      const int u = query[0];
      const int v = query[1];
      ans.push_back(isPrerequisite[u][v]);
    }

    return ans;
  }

  void dfs(const vector<vector<int>>& graph, int u, vector<bool>& used) {
    for (const int v : graph[u]) {
      if (used[v])
        continue;
      used[v] = true;
      dfs(graph, v, used);
    }
  }
};     
// class Solution {
// public:

//     bool dfs(unordered_map<int,vector<int>> adj,int src,int dest,vector<bool> visited)  {
//         visited[src] = true;

//         if(src==dest) return true;
//         bool isReachable = false;
//         for(auto &i : adj[src]){
//             if(!visited[i]){
//                 isReachable = isReachable || dfs(adj,i,dest,visited);
//             }
//         }
//         return isReachable;  
//     }
//     vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
//         unordered_map<int,vector<int>> adj;

//         for(auto &i : prerequisites){
//             int u = i[0];
//             int v = i[1];
//             adj[u].push_back(v);
//         }
//         int q= queries.size();
//         vector<bool> res(q);
//         for(int i=0;i<q;i++){
//             int u = queries[i][0];
//             int v = queries[i][1];
//             vector<bool> visited(numCourses,false);            
//             res[i] = dfs(adj,u,v,visited);
//         }
//     return res;
//     }
// };