// Given a binary tree with the following rules:

// root.val == 0
// For any treeNode:
// If treeNode.val has a value x and treeNode.left != null, then treeNode.left.val == 2 * x + 1
// If treeNode.val has a value x and treeNode.right != null, then treeNode.right.val == 2 * x + 2
// Now the binary tree is contaminated, which means all treeNode.val have been changed to -1.

// Implement the FindElements class:

// FindElements(TreeNode* root) Initializes the object with a contaminated binary tree and recovers it.
// bool find(int target) Returns true if the target value exists in the recovered binary tree.
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class FindElements
{
public:
    FindElements(TreeNode *root)
    {
        dfs(root, 0);
    }

    bool find(int target)
    {
        return vals.find(target) != vals.end();
    }

private:
    unordered_set<int> vals;

    void dfs(TreeNode *root, int val)
    {
        if (root == nullptr)
            return;

        root->val = val;
        vals.insert(val);
        dfs(root->left, val * 2 + 1);
        dfs(root->right, val * 2 + 2);
    }
};

int main()
{
    // Construct a simple contaminated binary tree.
    // Example tree structure (contaminated, e.g., all values set to -1 initially):
    //
    //        -1
    //       /  \
    //     -1    -1
    //    /     /  \
    //  -1    -1   -1
    //
    TreeNode *root = new TreeNode(-1);
    root->left = new TreeNode(-1);
    root->right = new TreeNode(-1);
    root->left->left = new TreeNode(-1);
    root->right->left = new TreeNode(-1);
    root->right->right = new TreeNode(-1);

    // Recover the tree using FindElements.
    FindElements finder(root);

    // Test the find function.
    int targets[] = {0, 1, 2, 3, 4, 5, 6};
    for (int target : targets)
    {
        cout << "find(" << target << "): " << (finder.find(target) ? "true" : "false") << endl;
    }

    // Clean up the allocated tree nodes.
    delete root->left->left;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
