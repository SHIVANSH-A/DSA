// You are given a string array words, and an array groups, both arrays having length n.

// The hamming distance between two strings of equal length is the number of positions at which the corresponding characters are different.

// You need to select the longest subsequence from an array of indices [0, 1, ..., n - 1], such that for the subsequence denoted as [i0, i1, ..., ik-1] having length k, the following holds:

// For adjacent indices in the subsequence, their corresponding groups are unequal, i.e., groups[ij] != groups[ij+1], for each j where 0 < j + 1 < k.
// words[ij] and words[ij+1] are equal in length, and the hamming distance between them is 1, where 0 < j + 1 < k, for all indices in the subsequence.
// Return a string array containing the words corresponding to the indices (in order) in the selected subsequence. If there are multiple answers, return any of them.

// Note: strings in words may be unequal in length.

// Greedy will not work - class Solution {
// public:
//     bool hammingDistance(string a,string b){
//         int count=0;
//         for(int i=0;i<a.size();i++){
//             if(a[i]!=b[i]) count++;
//         }
//         return count==1;
//     }
//     vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
//         int n = words.size();
//         vector<string> r;
//         r.push_back(words[0]);
//         for(int i=1;i<n;i++){
//             if(groups[i]!=groups[i-1] && words[i].size()==words[i-1].size()){
//                if(hammingDistance(words[i],words[i-1])) r.push_back(words[i]);
//             }
//         }
//         return r;
//     }
// };

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool hammingDistance(string a, string b)
    {
        int count = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] != b[i])
                count++;
            if (count > 1)
                return false;
        }
        return count == 1;
    }

    vector<string> getWordsInLongestSubsequence(vector<string> &words, vector<int> &groups)
    {
        int n = words.size();
        vector<string> r;
        vector<int> dp(n, 1);
        vector<int> PrevIndex(n, -1);
        int LIS = 1;
        int LISidx = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (groups[i] != groups[j] && words[i].size() == words[j].size() && hammingDistance(words[i], words[j]))
                {
                    if (dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        PrevIndex[i] = j;
                        if (LIS < dp[i])
                        {
                            LIS = dp[i];
                            LISidx = i;
                        }
                    }
                }
            }
        }

        while (LISidx != -1)
        {
            r.push_back(words[LISidx]);
            LISidx = PrevIndex[LISidx];
        }

        reverse(r.begin(), r.end());
        return r;
    }
};

int main()
{
    Solution sol;

    // Sample input
    vector<string> words = {"aaaa", "abaa", "baaa", "bbbb", "bbba", "abba"};
    vector<int> groups = {1, 2, 1, 3, 2, 3};

    vector<string> result = sol.getWordsInLongestSubsequence(words, groups);

    cout << "Longest valid subsequence of words:" << endl;
    for (const string &word : result)
    {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
