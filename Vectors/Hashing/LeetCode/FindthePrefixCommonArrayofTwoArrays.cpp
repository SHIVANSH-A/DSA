//
// Brute force - O(n^3)
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        vector<int> c(A.size(), 0);         // To store the prefix common array
        vector<int> freqa(A.size() + 1, 0); // Frequency array for elements in A
        vector<int> freqb(A.size() + 1, 0); // Frequency array for elements in B

        for (int i = 0; i < A.size(); i++)
        {
            freqa[A[i]]++; // Increment frequency of the current element in A
            freqb[B[i]]++; // Increment frequency of the current element in B

            int count = 0; // Counter for common elements

            // Iterate through the range of possible values to count common elements
            for (int j = 1; j <= A.size(); j++)
            {
                if (freqa[j] >= 1 && freqb[j] >= 1)
                { // Check if the element is in both arrays
                    count++;
                }
            }

            c[i] = count; // Store the count for the current prefix
        }

        return c; // Return the prefix common array
    }
};

int main()
{
    // Input arrays
    vector<int> A = {1, 3, 2, 4};
    vector<int> B = {3, 1, 2, 4};

    // Create an instance of the Solution class
    Solution solution;

    // Call the method and get the result
    vector<int> result = solution.findThePrefixCommonArray(A, B);

    // Print the result
    cout << "Prefix Common Array: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
