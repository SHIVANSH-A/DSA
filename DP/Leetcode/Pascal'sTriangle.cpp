// Given an integer numRows, return the first numRows of Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 

// Example 1:

// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
// Example 2:

// Input: numRows = 1
// Output: [[1]]
 

// Constraints:

// 1 <= numRows <= 30


// Concept - Num at ith row and jth col (0-indexed) is icj

#include <iostream>
#include <vector>
using namespace std;    

//Getting row only nth
// class Solution {
// public:
//     vector<int> getRow(int rowIndex) {
//         vector<int> r(rowIndex+1);
//         long long temp =r[0]=1;
//         for(int i=1;i<rowIndex;i++){
//             temp = temp * (rowIndex-i+1);
//             temp = temp/i;
//             r[i] = temp;
//         }
//         r[rowIndex] = 1;
//         return r;
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> generate(int numRows) {
//      vector<vector<int>> r;
//      vector<int> prev;
//      for(int i=0;i<numRows;i++){
//         vector<int> curr(i+1,1);
//         for(int j=1;j<i;j++){
//             curr[j] = prev[j-1]+prev[j];
//         }
//         prev = curr;
//         r.push_back(curr);
//      }
//      return r;   
//     }
// };
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> r;
        vector<int> prev;
        for (int i = 0; i < numRows; i++) {
            vector<int> curr(i + 1, 1);  // First and last elements are 1
            for (int j = 1; j < i; j++) {
                curr[j] = prev[j - 1] + prev[j];  // Fill in the middle values
            }
            prev = curr;        // Save current row for next iteration
            r.push_back(curr);  // Add current row to result
        }
        return r;
    }
};

int main() {
    Solution sol;
    int numRows;
    cout << "Enter number of rows for Pascal's Triangle: ";
    cin >> numRows;

    vector<vector<int>> result = sol.generate(numRows);

    cout << "\nPascal's Triangle:\n";
    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
