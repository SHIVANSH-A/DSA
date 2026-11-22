// A sentence is a list of tokens separated by a single space with no leading or trailing spaces. Every token is either a positive number consisting of digits 0-9 with no leading zeros, or a word consisting of lowercase English letters.

// For example, "a puppy has 2 eyes 4 legs" is a sentence with seven tokens: "2" and "4" are numbers and the other tokens such as "puppy" are words.
// Given a string s representing a sentence, you need to check if all the numbers in s are strictly increasing from left to right (i.e., other than the last number, each number is strictly smaller than the number on its right in s).

// Return true if so, or false otherwise.

// Intuition: Traverse the sentence word by word(using space), identify numeric words, and convert them into integers. Compare each number with the previous number; if the current number is not strictly greater, return false. Otherwise, update prev and continue.

#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution
{
public:
    int toNum(string s)
    {
        int num = 0;

        for (auto i : s)
        {
            num *= 10;
            num += (i - '0');
        }

        return num;
    }

    bool areNumbersAscending(string s)
    {
        int prev = INT_MIN;
        s.push_back(' ');

        string curr = "";
        bool num = false;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                if (num)
                {
                    int val = toNum(curr);

                    if (prev >= val)
                        return false;

                    prev = val;
                }

                curr = "";
            }
            else
            {
                curr += s[i];

                if (s[i] >= '0' && s[i] <= '9')
                    num = true;
                else
                    num = false;
            }
        }

        return true;
    }
};

int main()
{
    string s;

    cout << "Enter a sentence: ";
    getline(cin, s);

    Solution obj;

    if (obj.areNumbersAscending(s))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
