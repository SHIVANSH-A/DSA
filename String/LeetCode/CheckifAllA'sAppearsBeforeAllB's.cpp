// Given a string s consisting of only the characters 'a' and 'b', return true if every 'a' appears before every 'b' in the string. Otherwise, return false.

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool checkString(string s)
    {
        bool flag = false;

        for (auto c : s)
        {
            if (c == 'b')
                flag = true;

            if (c == 'a' && flag)
                return false;
        }

        return true;
    }
};

int main()
{
    string s;

    cout << "Enter a string: ";
    cin >> s;

    Solution obj;

    if (obj.checkString(s))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
