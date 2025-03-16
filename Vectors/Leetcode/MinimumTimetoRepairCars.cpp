// You are given an integer array ranks representing the ranks of some mechanics. ranksi is the rank of the ith mechanic. A mechanic with a rank r can repair n cars in r * n2 minutes.

// You are also given an integer cars representing the total number of cars waiting in the garage to be repaired.

// Return the minimum time taken to repair all the cars.

// Note: All the mechanics can repair the cars simultaneously.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    Solution sol;
    vector<int> ranks = {4, 2, 3, 1};
    int cars = 10;
    cout << sol.repairCars(ranks, cars) << endl;
    return 0;
}
class Solution
{
public:
    long long repairCars(vector<int> &ranks, int cars)
    {
        long l = 0;
        long r = static_cast<long>(ranges::min(ranks)) * cars * cars;

        while (l < r)
        {
            const long m = (l + r) / 2;
            if (numCarsFixed(ranks, m) >= cars)
                r = m;
            else
                l = m + 1;
        }

        return l;
    }

private:
    long numCarsFixed(const vector<int> &ranks, long minutes)
    {
        long carsFixed = 0;
        //    r * n^2 = minutes
        // -> n = sqrt(minutes / r)
        for (const int rank : ranks)
            carsFixed += sqrt(minutes / rank);
        return carsFixed;
    }
};