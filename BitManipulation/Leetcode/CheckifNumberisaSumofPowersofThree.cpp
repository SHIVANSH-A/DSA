// Given an integer n, return true if it is possible to represent n as the sum of distinct powers of three. Otherwise, return false.

// An integer y is a power of three if there exists an integer x such that y == 3x.
#include <iostream>

class Solution
{
public:
    bool checkPowersOfThree(int n)
    {
        while (n > 0)
        {
            if (n % 3 == 2)
            {
                return false;
            }
            n /= 3;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    int n;

    std::cout << "Enter a number: ";
    std::cin >> n;

    if (solution.checkPowersOfThree(n))
    {
        std::cout << n << " can be represented as a sum of distinct powers of three.\n";
    }
    else
    {
        std::cout << n << " cannot be represented as a sum of distinct powers of three.\n";
    }

    return 0;
}
