// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    Solution sol;
    vector<vector<int>> arr = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    vector<vector<int>> merged = sol.merge(arr);

    for (auto &interval : merged)
    {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    return 0;
}

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &arr)
    {
        if (arr.empty())
            return {};

        sort(arr.begin(), arr.end());
        vector<vector<int>> v;

        // Initialize with first interval
        v.push_back(arr[0]);
        int prevStrt = arr[0][0];
        int prevLst = arr[0][1];

        for (int i = 1; i < arr.size(); i++)
        {
            int n0 = arr[i][0];
            int n1 = arr[i][1];

            // Normal case
            if (prevLst < n0)
            {
                v.push_back(arr[i]);
                prevStrt = n0;
                prevLst = n1;
            }
            // Overlapping case but not both([1,3][2,4])
            else
            {
                v.back()[1] = max(prevLst, n1);
            }
            // Skip to add when both are overlapped ([1,4][2,3])
            //  Update prevStrt with min and prevLst with max for next iteration
            prevStrt = min(prevStrt, n0);
            prevLst = max(prevLst, n1);
        }

        return v;
    }
};
