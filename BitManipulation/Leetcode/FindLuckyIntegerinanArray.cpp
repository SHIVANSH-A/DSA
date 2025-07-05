// Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.

// Return the largest lucky integer in the array. If there is no lucky integer return -1.

// Example 1:

// Input: arr = [2,2,3,4]
// Output: 2
// Explanation: The only lucky number in the array is 2 because frequency[2] == 2.
// Example 2:

// Input: arr = [1,2,2,3,3,3]
// Output: 3
// Explanation: 1, 2 and 3 are all lucky numbers, return the largest of them.
// Example 3:

// Input: arr = [2,2,2,3,3]
// Output: -1
// Explanation: There are no lucky numbers in the array.

// Constraints:

// 1 <= arr.length <= 500
// 1 <= arr[i] <= 500

// this sol is specific for these constraints and will also work to 65535.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findLucky(vector<int> &arr)
    {
        int n = arr.size();

        // First loop: encode the count into higher 16 bits
        for (int num : arr)
        {
            int val = (num & 65535); // Get only lower 16 bits of num
            if (val <= n)
            {
                // Add 1 to higher 16 bits of arr[val - 1]
                // We use (1 << 16) = 65536, which sets a bit in higher 16 bits
                arr[val - 1] += (1 << 16);
            }
        }

        // Second loop: check from highest to lowest
        for (int i = n; i > 0; i--)
        {
            // Extract the count stored in higher 16 bits using >> 16
            if ((arr[i - 1] >> 16) == i)
            {
                return i; // i is the lucky number
            }
        }

        return -1; // No lucky number found
    }
};

// class Solution {
// public:
//     int findLucky(vector<int>& arr) {
//         unordered_map<int, int> freq;

//         // Step 1: Count frequency of each number
//         for (int num : arr) {
//             freq[num]++;
//         }

//         int result = -1;

//         // Step 2: Check if any number is "lucky"
//         for (auto& [num, count] : freq) {
//             if (num == count) {
//                 result = max(result, num); // Take the largest lucky number
//             }
//         }

//         return result;
//     }
// };

int main()
{
    Solution s;

    vector<int> arr = {2, 2, 3, 4};
    cout << "Lucky number: " << s.findLucky(arr) << endl;

    return 0;
}
