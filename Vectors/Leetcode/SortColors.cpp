// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

#include <iostream>
#include <vector>
#include <algorithm> // For std::swap
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int start = 0;
        int middle = 0;
        int end = nums.size() - 1;

        while (middle <= end)
        {
            if (nums[middle] == 0)
            {
                swap(nums[middle++], nums[start++]);
            }
            else if (nums[middle] == 2)
            {
                swap(nums[middle], nums[end--]);
            }
            else
            {
                middle++;
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    cout << "Original array: ";
    for (int n : nums)
        cout << n << " ";
    cout << endl;

    sol.sortColors(nums);

    cout << "Sorted array:   ";
    for (int n : nums)
        cout << n << " ";
    cout << endl;

    return 0;
}
