// You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.

// Return any such subsequence as an integer array of length k.

// A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

 

// Example 1:

// Input: nums = [2,1,3,3], k = 2
// Output: [3,3]
// Explanation:
// The subsequence has the largest sum of 3 + 3 = 6.
// Example 2:

// Input: nums = [-1,-2,3,4], k = 3
// Output: [-1,3,4]
// Explanation: 
// The subsequence has the largest sum of -1 + 3 + 4 = 6.
// Example 3:

// Input: nums = [3,4,3,3], k = 2
// Output: [3,4]
// Explanation:
// The subsequence has the largest sum of 3 + 4 = 7. 
// Another possible subsequence is [4, 3].
 

// Constraints:

// 1 <= nums.length <= 1000
// -105 <= nums[i] <= 105
// 1 <= k <= nums.length
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// class Solution {
// public:
//     vector<int> maxSubsequence(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<pair<int,int>> temp;
//         vector<int> r;
//         for(int i=0;i<n;i++){
//             temp.push_back({i,nums[i]});
//         }
//         auto lambda =[](pair<int,int> &x,pair<int,int> &y){
//             return x.second > y.second;
//         };
//         sort(temp.begin(),temp.end(),lambda);
//         sort(temp.begin(),temp.begin()+k);

//         for(int i=0;i<k;i++){
//             r.push_back(temp[i].second);
//         }

//         return r;
//     }
// };
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(nums); // Make a copy of nums
        vector<int> r;

        // Find the k-th largest element and partially sort to find top k values
        nth_element(temp.begin(), temp.begin() + k - 1, temp.end(), greater<int>());

        int klargest = temp[k - 1];  
        int kcount = count(temp.begin(), temp.begin() + k, klargest); 
        
        for (int &i : nums) {
            if (i > klargest) {
                r.push_back(i);
            } else if (i == klargest && kcount) {
                r.push_back(i);
                kcount--;
            }

            if (r.size() == k) break;
        }

        return r;
    }
};

// Utility function to print vector
void printVector(const vector<int>& v) {
    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    Solution sol;

    vector<int> nums = {3, 5, 2, 9, 1};
    int k = 3;

    vector<int> result = sol.maxSubsequence(nums, k);

    cout << "Max subsequence of length " << k << " is: ";
    printVector(result);

    return 0;
}
