// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stack;
        for (char c : s)
        {
            if (c == '(')
                stack.push(')');
            else if (c == '{')
                stack.push('}');
            else if (c == '[')
                stack.push(']');
            else if (stack.empty() || stack.top() != c)
                return false;
            else
                stack.pop();
        }
        return stack.empty();
    }
};

int main()
{
    Solution solution;
    string input;

    cout << "Enter a string of parentheses: ";
    cin >> input;

    if (solution.isValid(input))
    {
        cout << "The string is valid.\n";
    }
    else
    {
        cout << "The string is not valid.\n";
    }

    return 0;
}
