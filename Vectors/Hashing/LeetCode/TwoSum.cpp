// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // Hash map to store numbers and their indices
        unordered_map<int, int> freq;
        vector<int> ans;

        // Iterate through the array
        for (int i = 0; i < nums.size(); ++i)
        {
            // Calculate the complement needed to reach the target
            int complement = target - nums[i];

            // Check if the complement exists in the map
            if (freq.find(complement) != freq.end())
            {
                // If found, return the indices
                ans.push_back(i);
                ans.push_back(freq[complement]);
                return ans;
            }

            // If not found, add the current number and its index to the map
            freq[nums[i]] = i;
        }

        // Return an empty vector if no solution is found
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    // Call the twoSum function
    vector<int> result = solution.twoSum(nums, target);

    // Output the result
    if (!result.empty())
    {
        cout << "Indices: " << result[0] << ", " << result[1] << '\n';
    }
    else
    {
        cout << "No solution found.\n";
    }

    return 0;
}
