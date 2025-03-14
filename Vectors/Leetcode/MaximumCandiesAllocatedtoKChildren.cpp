// You are given a 0-indexed integer array candies. Each element in the array denotes a pile of candies of size candies[i]. You can divide each pile into any number of sub piles, but you cannot merge two piles together.

// You are also given an integer k. You should allocate piles of candies to k children such that each child gets the same number of candies. Each child can be allocated candies from only one pile of candies and some piles of candies may go unused.

// Return the maximum number of candies each child can get.
// int maximumCandies(vector<int>& candies, long long k) {
//     int n = candies.size();
//     auto m = max_element(candies.begin(),candies.end());
//     int max_ele = *m;

//     for(int c=max_ele;c>=1;c--){
//         long long count = 0;

//         for(int i=0;i<n;i++){
//             count+=candies[i]/c;
//         }
//         if(count>=k) return c;
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canDistribute(vector<int> &candies, long long k, int mid)
    {
        long long count = 0;

        for (int i = 0; i < candies.size(); i++)
        {
            count += candies[i] / mid;
        }
        if (count >= k)
            return true;
        return false;
    }

    int maximumCandies(vector<int> &candies, long long k)
    {
        int n = candies.size();
        auto m = max_element(candies.begin(), candies.end());
        int max_ele = *m;

        int l = 1;
        int r = max_ele;
        int res = 0;
        while (r >= l)
        {
            int mid = l + (r - l) / 2;

            if (canDistribute(candies, k, mid))
            {
                res = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return res;
    }
};