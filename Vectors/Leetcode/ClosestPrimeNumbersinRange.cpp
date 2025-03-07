// Given two positive integers left and right, find the two integers num1 and num2 such that:

// left <= num1 < num2 <= right .
// Both num1 and num2 are prime numbers.
// num2 - num1 is the minimum amongst all other pairs satisfying the above conditions.
// Return the positive integer array ans = [num1, num2]. If there are multiple pairs satisfying these conditions, return the one with the smallest num1 value. If no such numbers exist, return [-1, -1].
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    Solution sol;
    int left, right;

    cout << "Enter left and right range: ";
    cin >> left >> right;

    vector<int> result = sol.closestPrimes(left, right);

    cout << "Closest prime numbers: " << result[0] << " " << result[1] << endl;

    return 0;
}
class Solution
{
public:
    bool isPrime(int n)
    {
        if (n < 2)
            return false;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    vector<int> closestPrimes(int left, int right)
    {
        vector<int> v;

        for (int i = left; i <= right; i++)
        {
            if (isPrime(i))
                v.push_back(i);
        }

        if (v.size() < 2)
            return {-1, -1};

        vector<int> ans(2);

        int mindiff = INT_MAX;
        for (int i = 0; i < v.size() - 1; i++)
        {
            if (v[i + 1] - v[i] < mindiff)
            {
                mindiff = v[i + 1] - v[i];
                ans[0] = v[i];
                ans[1] = v[i + 1];
            }
        }

        return ans;
    }
};