// You are given a positive integer days representing the total number of days an employee is available for work (starting from day 1). You are also given a 2D array meetings of size n where, meetings[i] = [start_i, end_i] represents the starting and ending days of meeting i (inclusive).

// Return the count of days when the employee is available for work but no meetings are scheduled.

// Note: The meetings may overlap.
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    Solution sol;
    int days = 10;
    vector<vector<int>> arr = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};

    cout << "Remaining days: " << sol.countDays(days, arr) << endl;

    return 0;
}
class Solution
{
public:
    int countDays(int days, vector<vector<int>> &arr)
    {
        sort(arr.begin(), arr.end());
        // ,[] (const vector<int> &a,const vector <int> &b ){
        //     return a[0]<b[0];
        // });
        int sum = 0;
        int prevLst = 0;
        for (auto i : arr)
        {
            int n0 = i[0];
            int n1 = i[1];
            // Normal case ([1,2][3,4])
            if (prevLst < n0)
            {
                sum += i[1] - i[0] + 1;
            }
            // Overlapping but not both([1,3][2,4])
            else if (n1 > prevLst)
            {
                sum += n1 - prevLst;
            }
            // Skip to add when both are overlapped ([1,4][2,3])
            // Take max of last
            prevLst = max(prevLst, n1);
        }

        return days - sum;
    }
};