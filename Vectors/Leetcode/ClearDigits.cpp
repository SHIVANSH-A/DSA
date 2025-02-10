// You are given a string s.

// Your task is to remove all digits by doing this operation repeatedly:

// Delete the first digit and the closest non-digit character to its left.
// Return the resulting string after removing all digits.
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string clearDigits(string s)
    {
        string r;
        for (auto c : s)
        {
            if (isdigit(c))
            {
                if (!r.empty())
                    r.pop_back();
            }
            else
            {
                r += c;
            }
        }
        return r;
    }
};

int main()
{
    Solution sol;

    // Test cases
    string test1 = "abc1d2";       // Expected output: "a"
    string test2 = "a1b2c3";       // Expected output: ""
    string test3 = "x5y6z";        // Expected output: "x"
    string test4 = "1234";         // Expected output: ""
    string test5 = "hello1world2"; // Expected output: "hellowo"

    cout << "Result 1: " << sol.clearDigits(test1) << endl;
    cout << "Result 2: " << sol.clearDigits(test2) << endl;
    cout << "Result 3: " << sol.clearDigits(test3) << endl;
    cout << "Result 4: " << sol.clearDigits(test4) << endl;
    cout << "Result 5: " << sol.clearDigits(test5) << endl;

    return 0;
}
