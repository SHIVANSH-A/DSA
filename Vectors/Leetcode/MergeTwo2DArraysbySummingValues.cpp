// You are given two 2D integer arrays nums1 and nums2.

// nums1[i] = [idi, vali] indicate that the number with the id idi has a value equal to vali.
// nums2[i] = [idi, vali] indicate that the number with the id idi has a value equal to vali.
// Each array contains unique ids and is sorted in ascending order by id.

// Merge the two arrays into one array that is sorted in ascending order by id, respecting the following conditions:

// Only ids that appear in at least one of the two arrays should be included in the resulting array.
// Each id should be included only once and its value should be the sum of the values of this id in the two arrays. If the id does not exist in one of the two arrays, then assume its value in that array to be 0.
// Return the resulting array. The returned array must be sorted in ascending order by id.
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
    {
        vector<vector<int>> r;
        map<int, int> mpp;

        for (int i = 0; i < nums1.size(); i++)
        {
            mpp[nums1[i][0]] += nums1[i][1];
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            mpp[nums2[i][0]] += nums2[i][1];
        }

        for (auto &[key, value] : mpp)
        {
            // int sum  = accumulate(values.begin(),values.end(),0);
            r.push_back({key, value});
        }
        return r;
    }
};

int main()
{
    Solution sol;

    // Example test case
    vector<vector<int>> nums1 = {{1, 2}, {2, 3}, {4, 5}};
    vector<vector<int>> nums2 = {{1, 3}, {3, 4}, {4, 2}};

    // Call the function
    vector<vector<int>> result = sol.mergeArrays(nums1, nums2);

    // Print the result
    cout << "Merged Arrays:" << endl;
    for (const auto &row : result)
    {
        cout << "{" << row[0] << ", " << row[1] << "}" << endl;
    }

    return 0;
}