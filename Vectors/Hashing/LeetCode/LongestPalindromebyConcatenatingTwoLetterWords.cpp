// You are given an array of strings words. Each element of words consists of two lowercase English letters.

// Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.

// Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.

// A palindrome is a string that reads the same forward and backward.

// Example 1:

// Input: words = ["lc","cl","gg"]
// Output: 6
// Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
// Note that "clgglc" is another longest palindrome that can be created.
// Example 2:

// Input: words = ["ab","ty","yt","lc","cl","ab"]
// Output: 8
// Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
// Note that "lcyttycl" is another longest palindrome that can be created.
// Example 3:

// Input: words = ["cc","ll","xx"]
// Output: 2
// Explanation: One longest palindrome is "cc", of length 2.
// Note that "ll" is another longest palindrome that can be created, and so is "xx".

// Traverse over the vector and check if that string's reverse is present or not if it is present add 4 to result and decrement freq of its revrse else increment fre of string,then again check if a string with equal char is present add 2 to count and break as it can be added only once.
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        unordered_map<string, int> freq;
        int cnt = 0;
        bool flag = false;

        for (auto s : words)
        {
            if (s[0] != s[1])
            {
                string rev = s;
                reverse(rev.begin(), rev.end());
                if (freq[rev] > 0)
                {
                    cnt += 4;
                    freq[rev]--;
                }
                else
                {
                    freq[s]++;
                }
            }
            else
            {
                freq[s]++;
            }
        }

        for (auto &it : freq)
        {
            string s = it.first;
            int f = it.second;
            if (s[0] == s[1])
            {
                cnt += (f / 2) * 4;
                if (f % 2 == 1 && !flag)
                {
                    cnt += 2;
                    flag = true;
                }
            }
        }

        return cnt;
    }
};
// class Solution {
// public:
//      int longestPalindrome(vector<string>& words) {
//         unordered_map<string,int> freq;
//         int cnt = 0;

//         for(auto s: words){
//                 string rev = s;
//                 reverse(rev.begin(), rev.end());
//                 if(freq[rev] > 0){
//                     cnt += 4;
//                     freq[rev]--;
//                 } else {
//                     freq[s]++;
//                 }
//         }

//         for(auto& it: freq){
//             string s = it.first;
//             int f = it.second;
//             if(s[0] == s[1] && f>0){
//                 cnt += 2;
//                 break;
//             }
//         }

//         return cnt;
//     }
// };
int main()
{
    Solution sol;

    vector<string> words1 = {"ab", "ty", "yt", "lc", "cl", "ab"};
    vector<string> words2 = {"cc", "ll", "xx"};
    vector<string> words3 = {"ab", "ba", "cd", "dc", "ee"};

    cout << "Test 1 Result: " << sol.longestPalindrome(words1) << endl; // Output: 8
    cout << "Test 2 Result: " << sol.longestPalindrome(words2) << endl; // Output: 2
    cout << "Test 3 Result: " << sol.longestPalindrome(words3) << endl; // Output: 10

    return 0;
}
