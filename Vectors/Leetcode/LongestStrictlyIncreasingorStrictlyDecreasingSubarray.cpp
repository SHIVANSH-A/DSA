// You are given an array of integers nums. Return the length of the longest 
// subarray
//  of nums which is either 
// strictly increasing
//  or 
// strictly decreasing
// .
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int longestMonotonicSubarray(vector<int>& nums) {
    int ans = 1;
    int increasing = 1;
    int decreasing = 1;

    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1]) {
        increasing += 1;
        decreasing = 1;
      } else if (nums[i] < nums[i - 1]) {
        decreasing += 1;
        increasing = 1;
      } else {
        increasing = 1;
        decreasing = 1;
      }
      ans = max({ans, increasing, decreasing});
    }

    return ans;
  }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 2, 1, 4, 5, 6};
    cout << "Longest Monotonic Subarray Length: " << solution.longestMonotonicSubarray(nums) << endl;
    return 0;
}
