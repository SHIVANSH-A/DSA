// Given an array nums of distinct positive integers, return the number of tuples (a, b, c, d) such that a * b = c * d where a, b, c, and d are elements of nums, and a != b != c != d.
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    int tupleSameProduct(vector<int> &nums)
    {
        int l = nums.size();
        int cont = 0;
        map<int, vector<int>> mpp;

        for (int i = 0; i < l; i++)
        {
            for (int j = i + 1; j < l; j++)
            {
                mpp[nums[i] * nums[j]].push_back(nums[i]);
                mpp[nums[i] * nums[j]].push_back(nums[j]);
            }
        }

        for (auto &it : mpp)
        {
            int freq = it.second.size() / 2;
            if (freq > 1)
            {
                cont += (freq * (freq - 1)) / 2;
            }
        }

        return cont * 8;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 3, 4, 6};
    cout << sol.tupleSameProduct(nums) << endl;
    return 0;
}
