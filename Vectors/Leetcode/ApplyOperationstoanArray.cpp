// You are given a 0-indexed array nums of size n consisting of non-negative integers.

// You need to apply n - 1 operations to this array where, in the ith operation (0-indexed), you will apply the following on the ith element of nums:

// If nums[i] == nums[i + 1], then multiply nums[i] by 2 and set nums[i + 1] to 0. Otherwise, you skip this operation.
// After performing all the operations, shift all the 0's to the end of the array.

// For example, the array [1,0,2,0,0,1] after shifting all its 0's to the end, is [1,2,1,0,0,0].
// Return the resulting array.

// Note that the operations are applied sequentially, not all at once.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        vector<int> v(nums.size(), 0);
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                v[count++] = nums[i];
            }
        }
        return v;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 2, 0, 4, 4, 8}; // Example input

    cout << "Original array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> result = sol.applyOperations(nums);

    cout << "Modified array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
