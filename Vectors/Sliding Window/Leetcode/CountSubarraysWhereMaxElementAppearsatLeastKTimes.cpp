// You are given an integer array nums and a positive integer k.

// Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.

// A subarray is a contiguous sequence of elements within an array.

// class Solution {
//     public:
//         long long countSubarrays(vector<int>& nums, int k) {
//             int n = nums.size();
//             long long r = 0;
//             int m_ele = *max_element(nums.begin(),nums.end());
//             int i=0;
//             int j=0;
//             int count=0;
//             while(j<n){
//                 if(nums[j]==m_ele)count++;
//                 while(count>=k){
//                     r+=n-j;
//                     if(nums[i]==m_ele) count--;
//                     i++;
//                 }
//                 j++;
//             }
//             return r;
//         }
//     };
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        long long r = 0;
        int m_ele = *max_element(nums.begin(), nums.end());
        vector<int> indices;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == m_ele)
                indices.push_back(i);
            int size = indices.size();

            if (size >= k)
            {
                r += indices[size - k] + 1;
            }
        }
        return r;
    }
};

int main()
{
    Solution sol;

    // Example input
    vector<int> nums = {1, 3, 2, 3, 3};
    int k = 2;

    long long result = sol.countSubarrays(nums, k);
    cout << "Number of subarrays with at least " << k << " max elements: " << result << endl;

    return 0;
}
