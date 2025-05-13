// You are given a string s and an integer t, representing the number of transformations to perform. In one transformation, every character in s is replaced according to the following rules:

// If the character is 'z', replace it with the string "ab".
// Otherwise, replace it with the next character in the alphabet. For example, 'a' is replaced with 'b', 'b' is replaced with 'c', and so on.
// Return the length of the resulting string after exactly t transformations.

// Since the answer may be very large, return it modulo 109 + 7.
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int M = 1000000007;

    int lengthAfterTransformations(string s, int t)
    {
        vector<int> mpp(26, 0);
        // unordered_map<char,int> mpp;
        for (char i : s)
        {
            mpp[i - 'a']++;
        }

        while (t > 0)
        {
            // unordered_map<char,int> temp;
            vector<int> temp(26, 0);
            for (int it = 0; it < 26; it++)
            {
                if ((it + 'a') != 'z')
                {
                    temp[it + 1] = (temp[it + 1] + mpp[it]) % M;
                }
                else
                {
                    temp[0] = (temp[0] + mpp[25]) % M;
                    temp[1] = (temp[1] + mpp[25]) % M;
                }
            }
            mpp = move(temp);
            t--;
        }

        int sum = 0;
        for (auto it : mpp)
        {
            sum = (sum + it) % M;
        }

        return sum;
    }
};

int main()
{
    Solution sol;

    string s;
    int t;

    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter number of transformations t: ";
    cin >> t;

    int result = sol.lengthAfterTransformations(s, t);
    cout << "Length after transformations: " << result << endl;

    return 0;
}
