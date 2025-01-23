// -- Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

// -- Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
#include <iostream>
#include <limits.h>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        int reversedNumber = 0;

        while (x != 0)
        {
            if (reversedNumber < INT_MIN / 10 || reversedNumber > INT_MAX / 10)
            {
                return 0;
            }

            reversedNumber = reversedNumber * 10 + x % 10;
            x /= 10;
        }

        return reversedNumber;
    }
};

int main()
{
    Solution sol;
    int num;

    cout << "Enter an integer: ";
    cin >> num;

    int reversed = sol.reverse(num);

    if (reversed == 0)
    {
        cout << "Reversed integer overflows." << endl;
    }
    else
    {
        cout << "Reversed integer: " << reversed << endl;
    }

    return 0;
}