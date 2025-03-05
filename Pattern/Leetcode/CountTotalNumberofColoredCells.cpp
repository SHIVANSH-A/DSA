// There exists an infinitely large two-dimensional grid of uncolored unit cells. You are given a positive integer n, indicating that you must do the following routine for n minutes:

// At the first minute, color any arbitrary unit cell blue.
// Every minute thereafter, color blue every uncolored cell that touches a blue cell.
// Below is a pictorial representation of the state of the grid after minutes 1, 2, and 3.
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long coloredCells(int n)
    {
        return (2 * pow(n, 2)) - (2 * n) + 1;
    }
};

int main()
{
    Solution solution;
    int n;

    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Number of colored cells: " << solution.coloredCells(n) << endl;

    return 0;
}