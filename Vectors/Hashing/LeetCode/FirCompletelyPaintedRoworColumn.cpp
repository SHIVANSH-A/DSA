// You are given a 0-indexed integer array arr, and an m x n integer matrix mat. arr and mat both contain all the integers in the range [1, m * n].

// Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].

// Return the smallest index i at which either a row or a column will be completely painted in mat.
// Input: arr = [1,3,4,2], mat = [[1,4],[2,3]]
// Output: 2
// Explanation: The moves are shown in order, and both the first row and second column of the matrix become fully painted at arr[2].
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    Solution solution;

    // Example input
    vector<int> arr = {3, 2, 1, 4, 5};
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6}};

    // Call the function and print the result
    int result = solution.firstCompleteIndex(arr, mat);
    cout << "First complete index: " << result << endl;

    return 0;
}
class Solution
{
public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
    {
        vector<int> rowFreq(mat.size());
        vector<int> colFreq(mat[0].size());
        vector<int> targetRow(mat.size() * mat[0].size() + 1, 0);
        vector<int> targetCol(mat.size() * mat[0].size() + 1, 0);
        // For storing row and col of each number
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                targetRow[mat[i][j]] = i;
                targetCol[mat[i][j]] = j;
            }
        }
        // Checking if after updating the row and col freq if it matches to total number of cols or rows
        for (int i = 0; i < arr.size(); i++)
        {
            rowFreq[targetRow[arr[i]]]++;
            colFreq[targetCol[arr[i]]]++;
            if (rowFreq[targetRow[arr[i]]] == mat[0].size())
                return i;
            if (colFreq[targetCol[arr[i]]] == mat.size())
                return i;
        }
        return 0;
    }
};