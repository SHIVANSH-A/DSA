// Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

// Example 1:

// Input: n = 2
// Output: [0,1,1]
// Explanation:
// 0 --> 0
// 1 --> 1
// 2 --> 10
// Example 2:

// Input: n = 5
// Output: [0,1,1,2,1,2]
// Explanation:
// 0 --> 0
// 1 --> 1
// 2 --> 10
// 3 --> 11
// 4 --> 100
// 5 --> 101

// Constraints:

// 0 <= n <= 105

// Follow up:

// It is very easy to come up with a solution with a runtime of O(n log n). Can you do it in linear time O(n) and possibly in a single pass?
// Can you do it without using any built-in function (i.e., like __builtin_popcount in C++)?
#include <iostream>
#include <vector>
using namespace std;

// using odd even
// vector<int> countBits(int n) {
//     vector<int> r(n + 1, 0);
//    for (int i = 1; i <= n; i++) {
// If i is even, number of 1s is same as i/2
// If i is odd, it has one more 1 than i/2
//     r[i] = r[i / 2] + (i % 2);
// }
//     return r;
// }

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> r(n + 1);
        r[0] = 0;
        int ChangeNum = 0;
        int j = 0;
        for (int i = 1; i <= n; i++)
        {
            if (ChangeNum < r[i - 1])
            {
                ChangeNum = r[i - 1];
                j = 0;
            }
            r[i] = r[j] + 1;
            j++;
        }

        return r;
    }
};

int main()
{
    Solution sol;
    int n;
    cout << "Enter a number: ";
    cin >> n;

    vector<int> result = sol.countBits(n);

    cout << "Count of 1s in binary representation from 0 to " << n << ":\n";
    for (int i = 0; i <= n; i++)
    {
        cout << "Number " << i << " -> " << result[i] << " ones\n";
    }

    return 0;
}