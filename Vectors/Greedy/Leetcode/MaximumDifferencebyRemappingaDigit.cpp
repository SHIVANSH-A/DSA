// You are given an integer num. You know that Bob will sneakily remap one of the 10 possible digits (0 to 9) to another digit.

// Return the difference between the maximum and minimum values Bob can make by remapping exactly one digit in num.

// Notes:

// When Bob remaps a digit d1 to another digit d2, Bob replaces all occurrences of d1 in num with d2.
// Bob can remap a digit to itself, in which case num does not change.
// Bob can remap different digits for obtaining minimum and maximum values respectively.
// The resulting number after remapping can contain leading zeroes.
 

// Example 1:

// Input: num = 11891
// Output: 99009
// Explanation: 
// To achieve the maximum value, Bob can remap the digit 1 to the digit 9 to yield 99899.
// To achieve the minimum value, Bob can remap the digit 1 to the digit 0, yielding 890.
// The difference between these two numbers is 99009.
// Example 2:

// Input: num = 90
// Output: 99
// Explanation:
// The maximum value that can be returned by the function is 99 (if 0 is replaced by 9) and the minimum value that can be returned by the function is 0 (if 9 is replaced by 0).
// Thus, we return 99.
 

// Constraints:

// 1 <= num <= 108
#include <iostream>
#include <string>
using namespace std;

// class Solution {
// public:
//     int minMaxDifference(int num) {
//         string temp1 = to_string(num);
//         string temp2 = to_string(num);
//         int idx_max = temp1.find_first_not_of('9');
//         char digit_min=temp2[0];
//         replace(temp2.begin(),temp2.end(),digit_min,'0');
//         if(idx_max!=string::npos){
//             char digit_max = temp1[idx_max];
//             replace(temp1.begin(),temp1.end(),digit_max,'9');
//         }
            
//         return stoi(temp1) - stoi(temp2);
//     }
// };
class Solution {
public:
    int minMaxDifference(int num) {
        string numStr = to_string(num);
        int digitToMaxReplace = -1;
        int digitToMinReplace = numStr[0] - '0';

        string maxVersion, minVersion;

        // Find a digit to replace with 9 (for max)
        for (char ch : numStr) {
            if (ch != '9') {
                digitToMaxReplace = ch - '0';
                break;
            }
        }

        if (digitToMaxReplace == -1 || digitToMinReplace == -1)
            return num;

        for (char ch : numStr) {
            int digit = ch - '0';

            if (digit == digitToMaxReplace && digit == digitToMinReplace) {
                maxVersion += '9';
                minVersion += '0';
            } else if (digit == digitToMaxReplace) {
                maxVersion += '9';
                minVersion += ch;
            } else if (digit == digitToMinReplace) {
                maxVersion += ch;
                minVersion += '0';
            } else {
                maxVersion += ch;
                minVersion += ch;
            }
        }

        return stoi(maxVersion) - stoi(minVersion);
    }
};

int main() {
    Solution solution;

    int test1 = 11891;
    int test2 = 909;
    int test3 = 999;
    int test4 = 1001;

    cout << "Difference for " << test1 << ": " << solution.minMaxDifference(test1) << endl;
    cout << "Difference for " << test2 << ": " << solution.minMaxDifference(test2) << endl;
    cout << "Difference for " << test3 << ": " << solution.minMaxDifference(test3) << endl;
    cout << "Difference for " << test4 << ": " << solution.minMaxDifference(test4) << endl;

    return 0;
}
