// A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:

// It is ().
// It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
// It can be written as (A), where A is a valid parentheses string.
// You are given a parentheses string s and a string locked, both of length n. locked is a binary string consisting only of '0's and '1's. For each index i of locked,

// If locked[i] is '1', you cannot change s[i].
// But if locked[i] is '0', you can change s[i] to either '(' or ')'.
// Return true if you can make s a valid parentheses string. Otherwise, return false.
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

        wildCard = 0;
        opencnt = 0;
        closecnt = 0;
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