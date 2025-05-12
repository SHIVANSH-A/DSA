// You are given an integer array digits, where each element is a digit. The array may contain duplicates.

// You need to find all the unique integers that follow the given requirements:

// The integer consists of the concatenation of three elements from digits in any arbitrary order.
// The integer does not have leading zeros.
// The integer is even.
// For example, if the given digits were [1, 2, 3], integers 132 and 312 follow the requirements.

// Return a sorted array of the unique integers.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> freq(10, 0);
        vector<int> r;

        // Count frequency of each digit
        for (int i = 0; i < n; i++) {
            freq[digits[i]]++;
        }

        // Generate 3-digit even numbers
        for (int i = 1; i < 10; i++) {
            if (freq[i] == 0) continue;
            freq[i]--;

            for (int j = 0; j < 10; j++) {
                if (freq[j] == 0) continue;
                freq[j]--;

                for (int k = 0; k < 10; k += 2) { // even units place
                    if (freq[k] == 0) continue;
                    freq[k]--;

                    int num = i * 100 + j * 10 + k;
                    if (find(r.begin(), r.end(), num) == r.end()) {
                        r.push_back(num);
                    }

                    freq[k]++;
                }

                freq[j]++;
            }

            freq[i]++;
        }

        return r;
    }
};
// class Solution {
// public:
//     vector<int> findEvenNumbers(vector<int>& digits) {
//         int n = digits.size();
//         vector<int> r;
//         for(int i=0;i<n;i++){
//             for(int j =0;j<n;j++){
//                 for(int k=0;k<n;k++){
//                     if(i==j || j==k || i==k){
//                         continue;
//                     }
//                     int num = digits[i]*100 + digits[j]*10 + digits[k];
//                     if(num%2==0 && num>=100 && num<=999 && find(r.begin(),r.end(),num)==r.end()){
//                         r.push_back(num);
//                     }
//                 }
//             }
//         }
//         sort(r.begin(),r.end());
//         return r;
//     }
// };

int main() {
    Solution sol;

    // Example input
    vector<int> digits = {2, 1, 3, 0};

    vector<int> result = sol.findEvenNumbers(digits);

    cout << "3-digit even numbers formed: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
