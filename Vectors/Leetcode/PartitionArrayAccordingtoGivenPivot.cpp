// You are given a 0-indexed integer array nums and an integer pivot. Rearrange nums such that the following conditions are satisfied:

// Every element less than pivot appears before every element greater than pivot.
// Every element equal to pivot appears in between the elements less than and greater than pivot.
// The relative order of the elements less than pivot and the elements greater than pivot is maintained.
// More formally, consider every pi, pj where pi is the new position of the ith element and pj is the new position of the jth element. If i < j and both elements are smaller (or larger) than pivot, then pi < pj.
// Return nums after the rearrangement.
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> r;
        int n = nums.size();
        
        // First, add elements less than pivot
        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot) {
                r.push_back(nums[i]);
            }
        }
        
        // Then, add elements equal to pivot
        for (int i = 0; i < n; i++) {
            if (nums[i] == pivot) {
                r.push_back(nums[i]);
            }
        }
        
        // Finally, add elements greater than pivot
        for (int i = 0; i < n; i++) {
            if (nums[i] > pivot) {
                r.push_back(nums[i]);
            }
        }

        return r;
    }
};

// Main function to test the implementation
int main() {
    Solution sol;
    vector<int> nums = {9, 12, 5, 10, 14, 3, 10};
    int pivot = 10;

    vector<int> result = sol.pivotArray(nums, pivot);

    // Print the result
    cout << "Rearranged array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
