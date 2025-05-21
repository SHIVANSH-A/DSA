// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

// You must do it in place.

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        bool firstRowImpact = false;
        bool firstColImpact = false;

        // Check if first row has any zeros
        for (int i = 0; i < n; i++)
        {
            if (matrix[0][i] == 0)
                firstRowImpact = true;
        }

        // Check if first column has any zeros
        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] == 0)
                firstColImpact = true;
        }

        // Use first row and column as markers
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set zeroes based on markers
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // Zero out the first row if needed
        if (firstRowImpact)
        {
            for (int i = 0; i < n; i++)
            {
                matrix[0][i] = 0;
            }
        }

        // Zero out the first column if needed
        if (firstColImpact)
        {
            for (int i = 0; i < m; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};

// Helper function to print the matrix
void printMatrix(const vector<vector<int>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}
// space o(m+n)
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int m=matrix.size();
//         int n=matrix[0].size();
//         vector<bool> row(m,false);
//         vector<bool> col(n,false);

//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(matrix[i][j]==0){
//                     row[i] = true;
//                     col[j] = true;
//                 }
//             }
//         }
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(row[i]==true || col[j]==true){
//                     matrix[i][j]=0;
//                 }
//             }
//         }

//     }
// };
int main()
{
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}};

    cout << "Original matrix:\n";
    printMatrix(matrix);

    Solution sol;
    sol.setZeroes(matrix);

    cout << "\nMatrix after setZeroes:\n";
    printMatrix(matrix);

    return 0;
}
