// Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        int oddCount = 0;
        
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 != 0) {
                oddCount++;
                if (oddCount == 3) break;
            } else {
                oddCount = 0;
            }
        }
        return oddCount == 3;
    }
};
// class Solution {
// public:
//     bool threeConsecutiveOdds(vector<int>& arr) {
//         int n = arr.size();
//         bool flag = false;
//         if(n>2){
//             for(int i=2;i<n;i++){
//                 if(arr[i]%2!=0 && arr[i-1]%2!=0 && arr[i-2]%2!=0){
//                     flag = true;
//                     break;
//                 }
//             }
//         }
//         return flag;
        
//     }
// };
int main() {
    Solution sol;
    
    vector<int> arr1 = {2, 6, 4, 1}; // Output: false
    vector<int> arr2 = {1, 2, 34, 3, 4, 5, 7, 23, 12}; // Output: true (5, 7, 23)
    vector<int> arr3 = {1, 3, 5}; // Output: true

    cout << "Test Case 1: " << (sol.threeConsecutiveOdds(arr1) ? "true" : "false") << endl;
    cout << "Test Case 2: " << (sol.threeConsecutiveOdds(arr2) ? "true" : "false") << endl;
    cout << "Test Case 3: " << (sol.threeConsecutiveOdds(arr3) ? "true" : "false") << endl;

    return 0;
}
