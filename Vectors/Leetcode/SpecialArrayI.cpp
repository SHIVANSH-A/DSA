// An array is considered special if every pair of its adjacent elements contains two numbers with different parity.

// You are given an array of integers nums. Return true if nums is a special array, otherwise, return false.
#include <bits/stdc++.h>
using namespace std;
int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5}; // Example input
    
    if (solution.isArraySpecial(nums)) {
        cout << "The array is special." << endl;
    } else {
        cout << "The array is not special." << endl;
    }
    
    return 0;
}
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        bool flag=true;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]%2==0 && nums[i+1]%2==0) {
                flag = false;
                break;
            }
            else if(nums[i]%2!=0 && nums[i+1]%2!=0){
                flag = false;
                break;
            }
        }
        return flag;
    }
};