// Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

// A shift on s consists of moving the leftmost character of s to the rightmost position.

// For example, if s = "abcde", then it will be "bcdea" after one shift.

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        return s.size() == goal.size() && (s + s).find(goal) != string::npos;
    }
};

int main()
{
    Solution solution;

    // Test cases
    string s1 = "abcde", goal1 = "cdeab";
    string s2 = "abcde", goal2 = "abced";
    string s3 = "aa", goal3 = "aa";

    cout << "Input: s = \"" << s1 << "\", goal = \"" << goal1 << "\" -> Output: "
         << (solution.rotateString(s1, goal1) ? "true" : "false") << endl;

    cout << "Input: s = \"" << s2 << "\", goal = \"" << goal2 << "\" -> Output: "
         << (solution.rotateString(s2, goal2) ? "true" : "false") << endl;

    cout << "Input: s = \"" << s3 << "\", goal = \"" << goal3 << "\" -> Output: "
         << (solution.rotateString(s3, goal3) ? "true" : "false") << endl;

    return 0;
}
