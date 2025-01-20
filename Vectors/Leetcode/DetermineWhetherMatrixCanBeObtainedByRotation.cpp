// Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
    {
        for (int k = 0; k < 4; k++)
        {
            vector<vector<int>> rotated(mat.size(), vector<int>(mat.size()));
            for (int i = 0; i < mat.size(); i++)
            {
                for (int j = 0; j < mat.size(); j++)
                {
                    rotated[i][j] = mat[mat.size() - j - 1][i];
                }
            }
            if (rotated == target)
                return true;
            mat = rotated;
        }
        return false;
    }
};

int main()
{
    Solution solution;

    // Example matrices
    vector<vector<int>> mat = {
        {0, 1},
        {1, 0}};

    vector<vector<int>> target = {
        {1, 0},
        {0, 1}};

    // Call the function
    if (solution.findRotation(mat, target))
    {
        cout << "Yes, mat can be rotated to match target." << endl;
    }
    else
    {
        cout << "No, mat cannot be rotated to match target." << endl;
    }

    return 0;
}
