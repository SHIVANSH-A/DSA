// A 0-indexed array derived with length n is derived by computing the bitwise XOR (⊕) of adjacent values in a binary array original of length n.

// Specifically, for each index i in the range [0, n - 1]:

// If i = n - 1, then derived[i] = original[i] ⊕ original[0].
// Otherwise, derived[i] = original[i] ⊕ original[i + 1].
// Given an array derived, your task is to determine whether there exists a valid binary array original that could have formed derived.

// Return true if such an array exists or false otherwise.

// A binary array is an array containing only 0's and 1's
// a^b = z then z^b= a and z^a = b
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool doesValidArrayExist(vector<int> &derived)
    {
        vector<int> original(derived.size(), 0);
        // For original[0] = 0
        for (int i = 0; i < derived.size() - 1; i++)
        {
            original[i + 1] = original[i] ^ derived[i];
        }
        if (original[derived.size() - 1] ^ original[0] == derived[derived.size() - 1])
        {
            return true;
        }
        original.clear();
        // For original[0] = 1
        original.resize(derived.size(), 0);
        original[0] = 1;
        for (int i = 0; i < derived.size() - 1; i++)
        {
            original[i + 1] = original[i] ^ derived[i];
        }
        if (original[derived.size() - 1] ^ original[0] == derived[derived.size() - 1])
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Solution solution;

    // Test case 1
    vector<int> derived1 = {1, 0, 1};
    cout << "Test Case 1: " << (solution.doesValidArrayExist(derived1) ? "True" : "False") << endl;

    // Test case 2
    vector<int> derived2 = {1, 1, 0};
    cout << "Test Case 2: " << (solution.doesValidArrayExist(derived2) ? "True" : "False") << endl;

    // Test case 3
    vector<int> derived3 = {0, 0, 0};
    cout << "Test Case 3: " << (solution.doesValidArrayExist(derived3) ? "True" : "False") << endl;

    // Test case 4
    vector<int> derived4 = {1, 1, 1, 0};
    cout << "Test Case 4: " << (solution.doesValidArrayExist(derived4) ? "True" : "False") << endl;

    return 0;
}
