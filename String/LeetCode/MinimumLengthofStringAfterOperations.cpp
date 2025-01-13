// You are given a string s.

// You can perform the following process on s any number of times:

// Choose an index i in the string such that there is at least one character to the left of index i that is equal to s[i], and at least one character to the right that is also equal to s[i].
// Delete the closest character to the left of index i that is equal to s[i].
// Delete the closest character to the right of index i that is equal to s[i].
// Return the minimum length of the final string s that you can achieve.
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int minimumLength(string s)
    {
        vector<int> freq(26, 0);
        if (s.length() <= 2)
            return s.length();
        for (auto i : s)
        {
            freq[i - 'a']++;
        }
        int res = s.length();
        for (int i = 0; i < 26; i++)
        {
            while (freq[i] > 2)
            {
                freq[i] -= 2;
                res -= 2;
            }
        }
        return res;
    }
};

int main()
{
    Solution solution;
    string testString;

    cout << "Enter a string: ";
    cin >> testString;

    int result = solution.minimumLength(testString);
    cout << "The minimum length of the string after operations is: " << result << endl;

    return 0;
}
