// You are given a string word and a non-negative integer k.

// Return the total number of substrings of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') at least once and exactly k consonants.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    Solution sol;
    string word;
    int k;

    cout << "Enter the word: ";
    cin >> word;

    cout << "Enter the value of k: ";
    cin >> k;

    long long result = sol.countOfSubstrings(word, k);

    cout << "Count of valid substrings: " << result << endl;

    return 0;
}
class Solution
{
public:
    bool isVowel(char ch)
    {
        if (ch == 'a' || ch == 'e' || ch == 'o' || ch == 'u' || ch == 'i')
        {
            return true;
        }
        return false;
    }
    long long countOfSubstrings(string word, int k)
    {
        map<char, int> mpp;
        vector<int> v(word.size());
        int i = 0;
        int j = 0;
        int cons_count = 0;
        long long count = 0;
        int lastConsIdx = word.size();
        // PREPROCESSING - Making a vector which will store idx of next constant for each idx and for calculating count+= next_const_idx - j
        for (int i = word.size() - 1; i >= 0; i--)
        {
            v[i] = lastConsIdx;
            if (!isVowel(word[i]))
                lastConsIdx = i;
        }
        // sliding window
        while (j < word.size())
        {
            char ch = word[j];
            if (isVowel(ch))
            {
                mpp[ch]++;
            }
            else
            {
                cons_count++;
            }

            // First Condition for shrinking
            while (cons_count > k)
            {
                char ch = word[i];
                if (isVowel(ch))
                {
                    mpp[ch]--;
                    if (mpp[ch] == 0)
                    {
                        mpp.erase(ch);
                    }
                }
                else
                {
                    cons_count--;
                }
                i++;
            }

            // Calculating count and Second Condition for shrinking
            while (mpp.size() == 5 && cons_count == k)
            {
                int idx = v[j];
                count += idx - j;
                char ch = word[i];
                if (isVowel(ch))
                {
                    mpp[ch]--;
                    if (mpp[ch] == 0)
                        mpp.erase(ch);
                }
                else
                {
                    cons_count--;
                }
                i++;
            }

            j++;
        }

        return count;
    }
};