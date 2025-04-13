// A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

// For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
// Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.

// A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.
#include <iostream>
using namespace std;

class Solution
{
public:
    int M = 1e9 + 7;

    int findPower(long long a, long long b)
    {
        if (b < 1)
            return 1;

        long long temp = findPower(a, b / 2);
        long long result = (temp * temp) % M;
        if (b % 2 != 0)
            result = (result * a) % M;
        return result;
    }

    int countGoodNumbers(long long n)
    {
        long long a = findPower(5, (n + 1) / 2) % M;
        long long b = findPower(4, n / 2) % M;
        long long r = (a * b) % M;
        return r;
    }
};

int main()
{
    Solution sol;

    long long n;
    cout << "Enter the value of n (length of number): ";
    cin >> n;

    int result = sol.countGoodNumbers(n);
    cout << "Count of good numbers: " << result << endl;

    return 0;
}
