// You are given a 0-indexed array of strings words and a character x.

// Return an array of indices representing the words that contain the character x.

// Note that the returned array may be in any order.

// Example 1:

// Input: words = ["leet","code"], x = "e"
// Output: [0,1]
// Explanation: "e" occurs in both words: "leet", and "code". Hence, we return indices 0 and 1.
// Example 2:

// Input: words = ["abc","bcd","aaaa","cbc"], x = "a"
// Output: [0,2]
// Explanation: "a" occurs in "abc", and "aaaa". Hence, we return indices 0 and 2.
// Example 3:

// Input: words = ["abc","bcd","aaaa","cbc"], x = "z"
// Output: []
// Explanation: "z" does not occur in any of the words. Hence, we return an empty array.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for find

using namespace std;

class Solution
{
public:
    vector<int> findWordsContaining(vector<string> &words, char x)
    {
        vector<int> r;
        for (int i = 0; i < words.size(); i++)
        {
            if (find(words[i].begin(), words[i].end(), x) != words[i].end())
            {
                r.push_back(i);
            }
        }
        return r;
    }
};

int main()
{
    Solution sol;
    vector<string> words = {"apple", "banana", "cherry", "date"};
    char x = 'a';

    vector<int> result = sol.findWordsContaining(words, x);

    cout << "Indices of words containing '" << x << "': ";
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
