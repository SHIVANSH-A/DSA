// A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:

// It is ().
// It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
// It can be written as (A), where A is a valid parentheses string.
// You are given a parentheses string s and a string locked, both of length n. locked is a binary string consisting only of '0's and '1's. For each index i of locked,

// If locked[i] is '1', you cannot change s[i].
// But if locked[i] is '0', you can change s[i] to either '(' or ')'.
// Return true if you can make s a valid parentheses string. Otherwise, return false.
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool canBeValid(string s, string locked)
    {
        int wildCard = 0;
        int opencnt = 0;
        int closecnt = 0;
        if (s.size() % 2 != 0)
            return false;

        // Forward pass
        for (int i = 0; i < s.size(); ++i)
        {
            if (closecnt - opencnt > wildCard)
            {
                return false;
            }
            if (s[i] == '(' && locked[i] == '1')
                opencnt++;
            else if (s[i] == ')' && locked[i] == '1')
                closecnt++;
            else
                wildCard++;
        }
        if (closecnt - opencnt > wildCard)
        {
            return false;
        }

        // Reset counters for backward pass
        wildCard = 0;
        opencnt = 0;
        closecnt = 0;

        // Backward pass
        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (opencnt - closecnt > wildCard)
            {
                return false;
            }
            if (s[i] == '(' && locked[i] == '1')
                opencnt++;
            else if (s[i] == ')' && locked[i] == '1')
                closecnt++;
            else
                wildCard++;
        }
        if (opencnt - closecnt > wildCard)
        {
            return false;
        }

        return true;
    }
};

int main()
{
    // Test cases
    Solution solution;

    string s1 = "()()";
    string locked1 = "1100";
    cout << "Test Case 1: " << (solution.canBeValid(s1, locked1) ? "True" : "False") << endl;

    string s2 = "())";
    string locked2 = "101";
    cout << "Test Case 2: " << (solution.canBeValid(s2, locked2) ? "True" : "False") << endl;

    string s3 = "((())";
    string locked3 = "11111";
    cout << "Test Case 3: " << (solution.canBeValid(s3, locked3) ? "True" : "False") << endl;

    string s4 = "())(()";
    string locked4 = "000000";
    cout << "Test Case 4: " << (solution.canBeValid(s4, locked4) ? "True" : "False") << endl;

    return 0;
}
