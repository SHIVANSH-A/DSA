// You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.

// Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.
#include <bits/stdc++.h>
using namespace std;

int main() {
    Solution solution;
    string s1, s2;

    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    if (solution.areAlmostEqual(s1, s2)) {
        cout << "The strings are almost equal (one swap possible)." << endl;
    } else {
        cout << "The strings are not almost equal." << endl;
    }

    return 0;
}

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1==s2) return true;
        for(int i=0;i<s1.size();i++){
            for(int j=0;j<s2.size();j++){
                if(s1[i]!=s1[j]){
                    swap(s1[i],s1[j]);
                    if (s1==s2) return true;
                    swap(s1[i],s1[j]);
                }
            }
        }
        return false;
    }
};