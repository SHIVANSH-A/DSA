// You are given two positive integers n and k.

// An integer x is called k-palindromic if:

// x is a palindrome.
// x is divisible by k.
// An integer is called good if its digits can be rearranged to form a k-palindromic integer. For example, for k = 2, 2020 can be rearranged to form the k-palindromic integer 2002, whereas 1010 cannot be rearranged to form a k-palindromic integer.

// Return the count of good integers containing n digits.

// Note that any integer must not have leading zeros, neither before nor after rearrangement. For example, 1010 cannot be rearranged to form 101.
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution
{
public:
    long long fact(int num)
    {
        long long f = 1;
        for (int i = num; i > 0; i--)
        {
            f *= i;
        }
        return f;
    }

    long long countGoodIntegers(int n, int k)
    {
        unordered_set<string> st;
        int d = (n + 1) / 2;
        int start = pow(10, d - 1);
        int end = pow(10, d) - 1;

        for (int i = start; i <= end; i++)
        {
            string left_half = to_string(i);
            string full;
            if (n % 2 == 0)
            {
                string lft = left_half.substr(0, d);
                reverse(left_half.begin(), left_half.end());
                string rght = left_half;
                full = lft + rght;
            }
            else
            {
                string lft = left_half.substr(0, d - 1);
                char mid = left_half[d - 1];
                reverse(left_half.begin(), left_half.end() - 1);
                string rght = left_half.substr(0, d - 1);
                full = lft + mid + rght;
            }

            long long m = stoll(full);
            if (m % k != 0)
                continue;
            sort(full.begin(), full.end());
            st.insert(full);
        }

        long long count = 0;
        for (auto &s : st)
        {
            unordered_map<char, int> mpp;
            int non_zero = 0;
            for (char c : s)
            {
                mpp[c]++;
                if (c != '0')
                    non_zero++;
            }
            long long temp = non_zero * fact(s.size() - 1);
            long long freq_count = 1;
            for (auto &entry : mpp)
            {
                if (entry.second > 1)
                {
                    freq_count *= fact(entry.second);
                }
            }
            if (freq_count != 0)
            {
                temp /= freq_count;
            }
            count += temp;
        }

        return count;
    }
};

int main()
{
    Solution sol;

    int n, k;
    cout << "Enter the value of n (length of palindromes): ";
    cin >> n;

    cout << "Enter the value of k (divisibility check): ";
    cin >> k;

    long long result = sol.countGoodIntegers(n, k);
    cout << "Count of good integers: " << result << endl;

    return 0;
}
