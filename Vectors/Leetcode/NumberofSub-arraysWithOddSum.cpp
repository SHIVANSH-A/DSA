// Given an array of integers arr, return the number of subarrays with an odd sum.

// Since the answer can be very large, return it modulo 109 + 7.
// even+odd = odd and odd+even = odd (3 approaches)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numOfSubarrays(vector<int> &arr)
    {
        long long count = 0;
        // vector<int> p(arr.size());
        // p[0]=arr[0];
        // for(int i=1;i<arr.size();i++){
        //     p[i]=arr[i]+p[i-1];
        //     cout<<p[i]<<" ";
        // }
        long long evenCount = 1;
        long long oddCount = 0;
        long long sum = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            if (sum % 2 == 0)
            {
                evenCount++;
                count += oddCount;
            }
            else
            {
                oddCount++;
                count += evenCount;
            }
        }

        long long m = 1e9 + 7;
        return count % m;
    }
};
// long long count=0;
//         for(int i=0;i<arr.size();i++){
//             long long sum=0;
//             for(int j=i;j<arr.size();j++){
//                 sum+=arr[j];
//             if(sum%2!=0){
//                 count++;
//             }
//             }
//         }
int main()
{
    int n;
    cout << "Enter number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution sol;
    int result = sol.numOfSubarrays(arr);
    cout << "Number of subarrays with odd sum: " << result << endl;

    return 0;
}