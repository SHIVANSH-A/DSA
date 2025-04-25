// Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

// A subarray is a contiguous part of an array.
// Brute force - O(N^3)
// for(int i=0;i<n;i++){
//     for(int j=i;j<n;j++){
//         for(int k=i;k<=j;k++){
//             sum+=nums[k];
//         }
//         then checking sum%k
//     }
// }

// O(N^2)
// Calculate prefix sum
// for(int i=0;i<n;i++){
//     for(int j=i;j<n;j++){
//         sum = nums[j]-nums[i-1];
//         then checking sum%k
//     }
// }

// O(N)
// Modulo
// Array - [a,b,c,d,e]
// S1 sum from a->c
// S2 sum from a->e

// if S1%k ==S2%K then S2-S1%K==0

// Proof - S1 = K*N1 + R
// 	S2 = K*N2 + R
// S2-S1 = K(N2-N1) = KN

// So MAKE MAP WHICH STORES REMAINDER AND ITS COUNT
// WHENEVER A REMAINDER IS ALREADY IN MAP, ADD IT'S COUNT TO RESULT AND UPDATE COUNT

// FOR NEGATIVE REMAINDER ADD K TO IT MAKE IT POSITIVE
// PROOF - S1 = K*N-R + K - K
//         S1 = K(N-1) + (K-R)
//         NEW REMAINDER IS K-R
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        unordered_map<int, int> remCnt;
        int result = 0;
        int sum = 0;
        remCnt[0] = 1; // One way to have a sum with remainder 0
        int rem = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            rem = sum % k;

            if (rem < 0)
            {
                rem += k;
            }

            if (remCnt.find(rem) != remCnt.end())
            {
                result += remCnt[rem];
            }

            remCnt[rem]++;
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;

    int result = sol.subarraysDivByK(nums, k);
    cout << "Number of subarrays divisible by " << k << " is: " << result << endl;

    return 0;
}
