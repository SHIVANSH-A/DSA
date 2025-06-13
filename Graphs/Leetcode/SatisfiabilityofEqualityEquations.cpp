// You are given an array of strings equations that represent relationships between variables where each string equations[i] is of length 4 and takes one of two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are lowercase letters (not necessarily different) that represent one-letter variable names.

// Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.

// Example 1:

// Input: equations = ["a==b","b!=a"]
// Output: false
// Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
// There is no way to assign the variables to satisfy both equations.
// Example 2:

// Input: equations = ["b==a","a==b"]
// Output: true
// Explanation: We could assign a = 1 and b = 1 to satisfy both equations.
#include <iostream>
#include <vector>
#include <string>
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
        return parent[a] = find(parent[a]); // path compression
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

    bool equationsPossible(vector<string> &equations)
    {
        rank.resize(26, 0);
        parent.resize(26);
        for (int i = 0; i < 26; i++)
        {
            parent[i] = i;
        }

        // First pass: union the '==' equations
        for (auto &eq : equations)
        {
            if (eq[1] == '=')
            {
                Union(eq[0] - 'a', eq[3] - 'a');
            }
        }

        // Second pass: check the '!=' equations
        for (auto &eq : equations)
        {
            if (eq[1] == '!')
            {
                if (find(eq[0] - 'a') == find(eq[3] - 'a'))
                {
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    Solution sol;

    // Sample test case: returns false
    vector<string> equations = {"a==b", "e==c", "b==c", "a!=e"};

    if (sol.equationsPossible(equations))
    {
        cout << "Equations are satisfiable.\n";
    }
    else
    {
        cout << "Equations are not satisfiable.\n";
    }

    return 0;
}
