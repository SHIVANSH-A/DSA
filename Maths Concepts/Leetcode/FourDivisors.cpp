// Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors. If there is no such integer in the array, return 0.

// Example 1:

// Input: nums = [21,4,7]
// Output: 32
// Explanation:
// 21 has 4 divisors: 1, 3, 7, 21
// 4 has 3 divisors: 1, 2, 4
// 7 has 2 divisors: 1, 7
// The answer is the sum of divisors of 21 only.
// Example 2:

// Input: nums = [21,21]
// Output: 64
// Example 3:

// Input: nums = [1,2,3,4,5]
// Output: 0

// Sieve of Eratosthenes

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sumFourDivisors(vector<int> &nums)
    {
        int sum = 0;

        for (auto a : nums)
        {
            int count = 0;
            int temp = 0;

            for (int i = 1; i * i <= a; i++)
            {
                if (count > 4)
                    break;

                if (a % i == 0)
                {
                    int other = a / i;
                    if (i == other)
                    {
                        count++;
                        temp += i;
                    }
                    else
                    {
                        count += 2;
                        temp += i + other;
                    }
                }
            }

            if (count == 4)
                sum += temp;
        }
        return sum;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {21, 4, 7}; // example input
    cout << sol.sumFourDivisors(nums) << endl;

    return 0;
}
