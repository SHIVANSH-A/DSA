// A happy string is a string that:

// consists only of letters of the set ['a', 'b', 'c'].
// s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
// For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.

// Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.

// Return the kth string of this list or return an empty string if there are less than k happy strings of length n.
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    void solve(string &curr, vector<string> &r, int n) {
        if (curr.size() == n) {
            r.push_back(curr);
            return;
        }
        for (char c = 'a'; c <= 'c'; c++) {
            if (curr.empty() || curr.back() != c) {
                curr.push_back(c);
                solve(curr, r, n);
                curr.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        string curr;
        vector<string> r;
        solve(curr, r, n);
        if (r.size() < k) return "";
        return r[k - 1];
    }
};

int main() {
    Solution sol;
    int n, k;
    
    cout << "Enter value of n: ";
    cin >> n;
    cout << "Enter value of k: ";
    cin >> k;
    
    string result = sol.getHappyString(n, k);
    
    if (result.empty()) {
        cout << "The k-th happy string does not exist." << endl;
    } else {
        cout << "The " << k << "-th happy string is: " << result << endl;
    }
    
    return 0;
}
//using count instead of list
// class Solution {
//     public:
//         void solve(string &curr,int &r,int n,int k){
//             if(curr.size()==n){
//                 r++;
//                 return;
//             }
//             for(char c='a';c<='c';c++){
//                 if(curr.empty() || curr.back()!=c){
//                     curr.push_back(c);
//                     solve(curr,r,n,k);
//                     if(r==k) return;
//                     curr.pop_back();
//                 }
//             }
//         }
    
//         string getHappyString(int n, int k) {
//             string curr;
//             int r=0;
//             solve(curr,r,n,k);
//             if(r<k) return "";
//             return curr;
//         }
//     };
        
    