// You are given a 0-indexed integer array nums of size 3 which can form the sides of a triangle.

// A triangle is called equilateral if it has all sides of equal length.
// A triangle is called isosceles if it has exactly two sides of equal length.
// A triangle is called scalene if all its sides are of different lengths.
// Return a string representing the type of triangle that can be formed or "none" if it cannot form a triangle.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string triangleType(vector<int>& nums) {
        int equal = 0;
        // Triangle inequality check
        if ((nums[0] + nums[1] <= nums[2]) ||
            (nums[0] + nums[2] <= nums[1]) ||
            (nums[1] + nums[2] <= nums[0]))
            return "none";

        // Count equal sides
        if ((nums[0] == nums[1]) && (nums[0] == nums[2]))
            equal = 3;
        else if ((nums[0] == nums[1]) || (nums[0] == nums[2]) || (nums[1] == nums[2]))
            equal = 2;

        // Determine triangle type
        return (equal == 3) ? "equilateral" :
               (equal == 2) ? "isosceles" :
                              "scalene";
    }
};

int main() {
    Solution sol;
    vector<vector<int>> testCases = {
        {3, 3, 3},
        {3, 4, 5},
        {5, 5, 3},
        {1, 2, 3},  // Not a triangle
        {10, 1, 1}  // Not a triangle
    };

    for (auto& sides : testCases) {
        cout << "Sides: ";
        for (int s : sides) cout << s << " ";
        cout << "=> Type: " << sol.triangleType(sides) << endl;
    }

    return 0;
}
