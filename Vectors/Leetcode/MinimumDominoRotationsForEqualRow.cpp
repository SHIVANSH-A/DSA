// In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino. (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

// We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.

// Return the minimum number of rotations so that all the values in tops are the same, or all the values in bottoms are the same.

// If it cannot be done, return -1.
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int findMinStep(vector<int> &tops, vector<int> &bottoms, int val)
    {
        int topStep = 0;
        int bottomStep = 0;

        for (int i = 0; i < bottoms.size(); i++)
        {
            if (tops[i] != val && bottoms[i] != val)
                return -1;
            else if (tops[i] != val)
                topStep++;
            else if (bottoms[i] != val)
                bottomStep++;
        }
        return min(topStep, bottomStep);
    }

    int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
    {
        int r = INT_MAX;
        for (int i = 1; i <= 6; i++)
        {
            int steps = findMinStep(tops, bottoms, i);
            if (steps != -1)
            {
                r = min(steps, r);
            }
        }
        return (r == INT_MAX) ? -1 : r;
    }
};

int main()
{
    Solution sol;

    // Sample test case
    vector<int> tops = {2, 1, 2, 4, 2, 2};
    vector<int> bottoms = {5, 2, 6, 2, 3, 2};

    int result = sol.minDominoRotations(tops, bottoms);
    cout << "Minimum rotations: " << result << endl;

    return 0;
}
