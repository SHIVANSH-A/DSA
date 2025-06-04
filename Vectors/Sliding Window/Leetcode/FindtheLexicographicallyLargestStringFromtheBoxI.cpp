// You are given a string word, and an integer numFriends.

// Alice is organizing a game for her numFriends friends. There are multiple rounds in the game, where in each round:

// word is split into numFriends non-empty strings, such that no previous round has had the exact same split.
// All the split words are put into a box.
// Find the lexicographically largest string from the box after all the rounds are finished.

// Example 1:

// Input: word = "dbca", numFriends = 2

// Output: "dbc"

// Explanation:

// All possible splits are:

// "d" and "bca".
// "db" and "ca".
// "dbc" and "a".
// Example 2:

// Input: word = "gggg", numFriends = 4

// Output: "g"

// Explanation:

// The only possible split is: "g", "g", "g", and "g".
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
// class Solution {
// public:
//     string answerString(string word, int numFriends) {
//         int n=word.size();
//         if(numFriends==1) return word;
//         int longestPosi = n - (numFriends-1);
//         string r = "";
//         for(int i=0;i<n;i++){
//             int len = min(longestPosi,n-i);
//             r = max(r,word.substr(i,len));
//         }

//         return r;
//     }
// };

// class Solution {
// public:
//     string answerString(string word, int numFriends) {
//         int n=word.size();
//         if(numFriends==1) return word;
//         int longestPosi = n - (numFriends-1);
//         string r = "";
//         unordered_map<char,vector<int>> f;

//         for(int i=0;i<n;i++){
//             f[word[i]].push_back(i);
//         }
//         char ch = 'a';
//         for(auto i:f){
//             ch = max(ch,i.first);
//         }

//         for(auto i:f[ch]){
//             int len = min(longestPosi,n-i);
//             r = max(r,word.substr(i,len));
//         }

//         return r;
//     }
// };

class Solution
{
public:
    string answerString(string word, int numFriends)
    {
        int n = word.size();
        if (numFriends == 1)
            return word;

        int longestPosi = n - (numFriends - 1);
        string r = "";

        int i = 0, j = 1;
        while (j < n)
        {
            int k = 0;

            while (j + k < n && word[j + k] == word[i + k])
                k++;

            if (j + k < n && word[j + k] > word[i + k])
            {
                i = j;
                j++;
            }
            else
            {
                j += ++k;
            }
        }

        int len = min(longestPosi, n - i);
        r = max(r, word.substr(i, len));

        return r;
    }
};

int main()
{
    Solution sol;

    // Test Case 1
    string word1 = "leetcode";
    int numFriends1 = 3;
    cout << "Answer String: " << sol.answerString(word1, numFriends1) << endl;

    // Test Case 2
    string word2 = "abab";
    int numFriends2 = 2;
    cout << "Answer String: " << sol.answerString(word2, numFriends2) << endl;

    // Test Case 3
    string word3 = "zxyabc";
    int numFriends3 = 4;
    cout << "Answer String: " << sol.answerString(word3, numFriends3) << endl;

    return 0;
}
