// Given an array nums sorted in non-decreasing order, return the maximum between the number of positive integers and the number of negative integers.

// In other words, if the number of positive integers in nums is pos and the number of negative integers is neg, then return the maximum of pos and neg.
// Note that 0 is neither positive nor negative.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        nums.erase(remove(nums.begin(), nums.end(), 0), nums.end());
        int i = 0;
        for (i; i < nums.size(); i++) {
            if (nums[i] > 0) break;
        }

        int r = max(i, (int)nums.size() - i);
        return r;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-3, -2, -1, 0, 0, 1, 2, 3};
    int result = sol.maximumCount(nums);
    cout << "Maximum Count: " << result << endl;
    return 0;
}
// class Solution {
//     public:
//         int maximumCount(vector<int>& nums) {
//             int neg_count = binarySearch(nums, 0);
//             int pos_count = nums.size() - binarySearch(nums, 1);
//             return max(neg_count, pos_count);
//         }
    
//     private:
//         int binarySearch(vector<int>& nums, int target) {
//             int left = 0, right = nums.size() - 1, result = nums.size();
            
//             while (left <= right) {
//                 int mid = (left + right) / 2;
//                 if (nums[mid] < target) {
//                     left = mid + 1;
//                 } else {
//                     result = mid;
//                     right = mid - 1;
//                 }
//             }
            
//             return result;
//         }
//     };