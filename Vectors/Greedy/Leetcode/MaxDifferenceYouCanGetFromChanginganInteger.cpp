// You are given an integer num. You will apply the following steps to num two separate times:

// Pick a digit x (0 <= x <= 9).
// Pick another digit y (0 <= y <= 9). Note y can be equal to x.
// Replace all the occurrences of x in the decimal representation of num by y.
// Let a and b be the two results from applying the operation to num independently.

// Return the max difference between a and b.

// Note that neither a nor b may have any leading zeros, and must not be 0.

 

// Example 1:

// Input: num = 555
// Output: 888
// Explanation: The first time pick x = 5 and y = 9 and store the new integer in a.
// The second time pick x = 5 and y = 1 and store the new integer in b.
// We have now a = 999 and b = 111 and max difference = 888
// Example 2:

// Input: num = 9
// Output: 8
// Explanation: The first time pick x = 9 and y = 9 and store the new integer in a.
// The second time pick x = 9 and y = 1 and store the new integer in b.
// We have now a = 9 and b = 1 and max difference = 8
 

// Constraints:

// 1 <= num <= 108
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDiff(int num) {
        string temp1 = to_string(num);
        string temp2 = to_string(num);

        // Create the maximum number by replacing the first non-9 digit with 9
        int idx_max = temp1.find_first_not_of('9');
        if (idx_max != string::npos) {
            char digit_max = temp1[idx_max];
            replace(temp1.begin(), temp1.end(), digit_max, '9');
        }

        // Create the minimum number by replacing the first suitable digit
        char digit_min = '-';
        for (int i = 0; i < temp2.size(); i++) {
            if (temp2[i] != '0' && temp2[i] != '1') {
                digit_min = temp2[i];
                break;
            }
        }
        if (digit_min != '-') {
            if (digit_min == temp2[0]) {
                replace(temp2.begin(), temp2.end(), digit_min, '1');
            } else {
                replace(temp2.begin(), temp2.end(), digit_min, '0');
            }
        }

        return stoi(temp1) - stoi(temp2);
    }
};

int main() {
    Solution sol;

    int num;
    cout << "Enter a number: ";
    cin >> num;

    int result = sol.maxDiff(num);
    cout << "Maximum difference: " << result << endl;

    return 0;
}
