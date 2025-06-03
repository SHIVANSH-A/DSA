// There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

// You are giving candies to these children subjected to the following requirements:

// Each child must have at least one candy.
// Children with a higher rating get more candies than their neighbors.
// Return the minimum number of candies you need to have to distribute the candies to the children.

// Example 1:

// Input: ratings = [1,0,2]
// Output: 5
// Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
// Example 2:

// Input: ratings = [1,2,2]
// Output: 4
// Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
// The third child gets 1 candy because it satisfies the above two conditions.

// Approach I
// Using two vectors for keeping track of both directions to compare.

// Approach II
// Using concept of peak and dip.
#include <iostream>
#include <vector>
#include <algorithm> // for min

using namespace std;
// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//         int n = ratings.size();
//         vector<int> left(n, 1);
//         vector<int> right(n, 1);
//         for (int i = 1; i < n; ++i) {
//             if (ratings[i] > ratings[i - 1]) {
//                 left[i] = left[i - 1] + 1;
//             }
//         }
//         for (int i = n - 2; ~i; --i) {
//             if (ratings[i] > ratings[i + 1]) {
//                 right[i] = right[i + 1] + 1;
//             }
//         }
//         int ans = 0;
//         for (int i = 0; i < n; ++i) {
//             ans += max(left[i], right[i]);
//         }
//         return ans;
//     }
// };
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        int ans = n; // At least 1 candy per child
        int i = 1;

        while (i < n)
        {
            if (ratings[i - 1] == ratings[i])
            {
                i++;
                continue;
            }

            int peak = 0;
            while (i < n && ratings[i - 1] < ratings[i])
            {
                peak++;
                ans += peak;
                i++;
            }

            int dip = 0;
            while (i < n && ratings[i - 1] > ratings[i])
            {
                dip++;
                ans += dip;
                i++;
            }

            ans -= min(peak, dip); // Adjust overlapping candy at the peak/dip junction
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    // Test case
    vector<int> ratings = {1, 0, 2}; // Expected output: 5

    int result = sol.candy(ratings);
    cout << "Minimum candies required: " << result << endl;

    // Another test case
    ratings = {1, 2, 2}; // Expected output: 4
    result = sol.candy(ratings);
    cout << "Minimum candies required: " << result << endl;

    return 0;
}
