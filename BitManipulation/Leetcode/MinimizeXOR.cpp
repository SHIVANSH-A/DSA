// Given two positive integers num1 and num2, find the positive integer x such that:

// x has the same number of set bits as num2, and
// The value x XOR num1 is minimal.
// Note that XOR is the bitwise XOR operation.

// Return the integer x. The test cases are generated such that x is uniquely determined.

// The number of set bits of an integer is the number of 1's in its binary representation.
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isSet(int x, int bits)
    {
        return (x & (1 << bits)) != 0;
    }

    int setBit(int &x, int bits)
    {
        return x | (1 << bits);
    }

    int unsetBit(int &x, int bits)
    {
        return x & ~(1 << bits);
    }

    int minimizeXor(int num1, int num2)
    {
        int x = num1;
        int req = __builtin_popcount(num2);
        int curr = __builtin_popcount(x);
        int bits = 0;

        if (curr < req)
        {
            while (curr < req)
            {
                if (!isSet(x, bits))
                {
                    x = setBit(x, bits);
                    curr++;
                }
                bits++;
            }
        }
        else if (curr > req)
        {
            while (curr > req)
            {
                if (isSet(x, bits))
                {
                    x = unsetBit(x, bits);
                    curr--;
                }
                bits++;
            }
        }
        return x;
    }
};

int main()
{
    Solution solution;

    // Example inputs
    int num1 = 25; // Binary: 11001
    int num2 = 5;  // Binary: 101 (3 set bits)

    // Function call
    int result = solution.minimizeXor(num1, num2);

    // Output the result
    cout << "The minimized XOR result is: " << result << endl;

    return 0;
}
