// In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino. (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

// We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.

// Return the minimum number of rotations so that all the values in tops are the same, or all the values in bottoms are the same.

// If it cannot be done, return -1.
#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        string ans(n, '.'); 
        vector<int> leftClosestR(n);
        vector<int> rightClosestL(n);

        // Fill the leftClosestR array with the nearest R to the left (or -1)
        for (int i = 0; i < n; i++) {
            if (dominoes[i] == 'L' || (dominoes[i] == '.' && i == 0)) {
                leftClosestR[i] = -1;
            } else if (dominoes[i] == '.' && i != 0) {
                leftClosestR[i] = leftClosestR[i - 1];
            } else {
                leftClosestR[i] = i;
            }
        }

        // Fill the rightClosestL array with the nearest L to the right (or -1)
        for (int i = n - 1; i >= 0; i--) {
            if (dominoes[i] == 'R' || (dominoes[i] == '.' && i == n - 1)) {
                rightClosestL[i] = -1;
            } else if (dominoes[i] == '.' && i != n - 1) {
                rightClosestL[i] = rightClosestL[i + 1];
            } else {
                rightClosestL[i] = i;
            }
        }

        // Determine the final state for each domino
        for (int i = 0; i < n; i++) {
            if (dominoes[i] != '.') {
                ans[i] = dominoes[i];
                continue;
            }
            int distNearestR = (leftClosestR[i] == -1) ? INT_MAX : abs(i - leftClosestR[i]);
            int distNearestL = (rightClosestL[i] == -1) ? INT_MAX : abs(i - rightClosestL[i]);

            if (distNearestR == distNearestL) ans[i] = '.';
            else if (distNearestR > distNearestL) ans[i] = 'L';
            else ans[i] = 'R';
        }

        return ans;
    }
};

int main() {
    Solution sol;
    string input = ".L.R...LR..L..";
    string result = sol.pushDominoes(input);
    cout << "Input:  " << input << endl;
    cout << "Output: " << result << endl;
    return 0;
}
