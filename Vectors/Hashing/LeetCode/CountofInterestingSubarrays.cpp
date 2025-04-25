// You are given a 0-indexed integer array nums, an integer modulo, and an integer k.

// Your task is to find the count of subarrays that are interesting.

// A subarray nums[l..r] is interesting if the following condition holds:

// Let cnt be the number of indices i in the range [l, r] such that nums[i] % modulo == k. Then, cnt % modulo == k.
// Return an integer denoting the count of interesting subarrays.

// Note: A subarray is a contiguous non-empty sequence of elements within an array.

// Take 1 and 0 if nums[i]%==k or not
// Then we will traverse over this vector
// Now S1 has rem r1
//     S2 has rem r2

//     Now r1 = sum%m
//     We want (S2-S1)%m == k
//     (S1%m -S2%m)%m == k
//     (r1 - r2 + m)%m==k  For neg rem
//     (r1 - k + m)%m==r2
//     Now we'll look for r2 is prev present in map or not

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    long long countInterestingSubarrays(vector<int> &nums, int m, int k)
    {
        vector<int> count(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % m == k)
                count[i] = 1;
            else
                count[i] = 0;
        }

        unordered_map<int, int> remCount;
        long long sum = 0;
        long long r = 0;
        remCount[0] = 1;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += count[i];
            long long r1 = sum % m;
            long long r2 = (r1 - k + m) % m;

            if (remCount.find(r2) != remCount.end())
                r += remCount[r2];

            remCount[r1]++;
        }

        return r;
    }
};

int main()
{
    Solution sol;

    // Sample input
    vector<int> nums = {3, 1, 9, 6};
    int m = 3;
    int k = 0;

    // Function call
    long long result = sol.countInterestingSubarrays(nums, m, k);

    // Output the result
    cout << "Number of interesting subarrays: " << result << endl;

    return 0;
}
