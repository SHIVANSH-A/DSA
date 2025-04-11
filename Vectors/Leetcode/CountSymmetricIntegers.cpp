// You are given two positive integers low and high.

// An integer x consisting of 2 * n digits is symmetric if the sum of the first n digits of x is equal to the sum of the last n digits of x. Numbers with an odd number of digits are never symmetric.

// Return the number of symmetric integers in the range [low, high].
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int countSymmetricIntegers(int low, int high)
    {
        int cnt = 0;
        for (int j = low; j <= high; j++)
        {
            string num1 = to_string(j);
            int halfsum = 0;
            if (num1.size() % 2 != 0)
                continue;
            for (int i = 0; i < num1.size() / 2; i++)
            {
                halfsum += num1[i] - '0';
            }
            for (int i = num1.size() / 2; i < num1.size(); i++)
            {
                halfsum -= num1[i] - '0';
            }
            if (halfsum == 0)
                cnt++;
        }
        return cnt;
    }
};

int main()
{
    Solution sol;
    int low = 1, high = 1000; // You can change these values for different test cases
    int result = sol.countSymmetricIntegers(low, high);
    cout << "Count of symmetric integers between " << low << " and " << high << " is: " << result << endl;
    return 0;
}
