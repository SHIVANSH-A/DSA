// You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.

// Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.

// In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int M = 1000000007;

    int numTilings(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        if (n == 3)
            return 5;

        vector<int> v(n);
        v[0] = 1;
        v[1] = 2;
        v[2] = 5;

        for (int i = 3; i < n; i++)
        {
            v[i] = (2LL * v[i - 1] % M + v[i - 3] % M) % M;
        }

        return v[n - 1];
    }
};

int main()
{
    Solution sol;
    int n;

    cout << "Enter the value of n: ";
    cin >> n;

    int result = sol.numTilings(n);
    cout << "Number of ways to tile a 2 x " << n << " board: " << result << endl;

    return 0;
}
