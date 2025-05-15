// You are given a string array words and a binary array groups both of length n, where words[i] is associated with groups[i].

// Your task is to select the longest alternating subsequence from words. A subsequence of words is alternating if for any two consecutive strings in the sequence, their corresponding elements in the binary array groups differ. Essentially, you are to choose strings such that adjacent elements have non-matching corresponding bits in the groups array.

// Formally, you need to find the longest subsequence of an array of indices [0, 1, ..., n - 1] denoted as [i0, i1, ..., ik-1], such that groups[ij] != groups[ij+1] for each 0 <= j < k - 1 and then find the words corresponding to these indices.

// Return the selected subsequence. If there are multiple answers, return any of them.

// Note: The elements in words are distinct.
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> getLongestSubsequence(vector<string> &words, vector<int> &groups)
    {
        int n = groups.size();
        vector<string> r;
        if (n == 0)
            return r;
        r.push_back(words[0]);
        for (int i = 1; i < n; i++)
        {
            if (groups[i] != groups[i - 1])
            {
                r.push_back(words[i]);
            }
        }
        return r;
    }
};

int main()
{
    vector<string> words = {"a", "b", "c", "d", "e"};
    vector<int> groups = {1, 1, 2, 2, 3};

    Solution sol;
    vector<string> result = sol.getLongestSubsequence(words, groups);

    cout << "Longest subsequence: ";
    for (const string &word : result)
    {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
