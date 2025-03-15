// There are several consecutive houses along a street, each of which has some money inside. There is also a robber, who wants to steal money from the homes, but he refuses to steal from adjacent homes.

// The capability of the robber is the maximum amount of money he steals from one house of all the houses he robbed.

// You are given an integer array nums representing how much money is stashed in each house. More formally, the ith house from the left has nums[i] dollars.

// You are also given an integer k, representing the minimum number of houses the robber will steal from. It is always possible to steal at least k houses.

// Return the minimum capability of the robber out of all the possible ways to steal at least k houses.

// Brute force - DP
// Optimal - Minimize the max or Maximize the min -> Binary Search

#include <bits/stdc++.h>
using namespace std;
int main()
{
    Solution sol;
    vector<int> nums = {2, 3, 5, 9};
    int k = 2;
    cout << sol.minCapability(nums, k) << endl;
    return 0;
}
class Solution
{
public:
    bool isPossible(vector<int> &nums, int mid, int k)
    {
        int n = nums.size();
        // Linear as if any mid is valid then k is possible
        //  int house = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= mid)
            {
                k--;
                // house++;
                i++;
            }
        }

        return k <= 0;
        // return house>=k;
    }
    int minCapability(vector<int> &nums, int k)
    {
        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());

        int result = r;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (isPossible(nums, mid, k))
            {
                result = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return result;
    }
};
// int minCapability(vector<int>& nums, int k) {
//       int m = solve(nums,0,k);
//       return m;
//     }
// int solve(vector<int>& nums, int i,int k){
//         if(k<=0){
//             return 0;
//         }

//         if(i>=nums.size()){
//             return INT_MAX;
//         }

//         int take = max(nums[i],solve(nums,i+2,k-1));
//         int notTak = solve(nums,i+1,k);

//         return min(take,notTak);
//     }