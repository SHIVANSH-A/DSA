// We run a preorder depth-first search (DFS) on the root of a binary tree.

// At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.

// If a node has only one child, that child is guaranteed to be the left child.

// Given the output traversal of this traversal, recover the tree and return its root.

#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <iostream>
#include <string>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    TreeNode *recoverFromPreorder(string traversal)
    {
        int i = 0;
        return recoverFromPreorder(traversal, 0, i);
    }

private:
    TreeNode *recoverFromPreorder(const string &traversal, int depth, int &i)
    {
        int nDashes = 0;
        while (i + nDashes < traversal.length() && traversal[i + nDashes] == '-')
            ++nDashes;
        if (nDashes != depth)
            return nullptr;

        i += depth;
        const int start = i;
        while (i < traversal.length() && isdigit(traversal[i]))
            ++i;

        return new TreeNode(stoi(traversal.substr(start, i - start)),
                            recoverFromPreorder(traversal, depth + 1, i),
                            recoverFromPreorder(traversal, depth + 1, i));
    }
};

// Helper function to print tree in pre-order
void printPreorder(TreeNode *root)
{
    if (!root)
        return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main()
{
    Solution sol;
    string traversal = "1-2--3--4-5--6--7";
    TreeNode *root = sol.recoverFromPreorder(traversal);

    cout << "Pre-order traversal of recovered tree: ";
    printPreorder(root);
    cout << endl;

    return 0;
}
