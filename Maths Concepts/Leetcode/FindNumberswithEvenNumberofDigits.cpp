// Given an array nums of integers, return how many of them contain an even number of digits.
// class Solution {
//     public:
//         int findNumbers(vector<int>& nums) {
//             int n = nums.size();
//             int r = 0;
//             for(int i=0;i<n;i++){
//                 string str = to_string(nums[i]);
//                 if(str.size()%2==0) r++;
//             }
//             return r;
//         }
//     };

//     class Solution {
//         public:
//             int findNumbers(vector<int>& nums) {
//                 int n = nums.size();
//                 int r = 0;
//                 for(int i=0;i<n;i++){
//                     int t  = floor(log10(nums[i]))+1;
//                     if(t%2==0) r++;
//                 }
//                 return r;
//             }
//         };

//         class Solution {
//             public:
//                 int findNumbers(vector<int>& nums) {
//                     int n = nums.size();
//                     int r = 0;
//                     for(int i=0;i<n;i++){
//                         int t  = ceil(log10(nums[i]+1));
//                         if(t%2==0) r++;
//                     }
//                     return r;
//                 }
//             };
#include <iostream>
#include <vector>
#include <cmath> // for log10() and floor()

using namespace std;

class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int n = nums.size();
        int r = 0;
        for (int i = 0; i < n; i++)
        {
            int t = floor(log10(nums[i])) + 1; // count number of digits
            if (t % 2 == 0)
                r++; // check if number of digits is even
        }
        return r;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {12, 345, 2, 6, 7896};
    int result = sol.findNumbers(nums);
    cout << "Count of numbers with even number of digits: " << result << endl;
    return 0;
}
