// You are given an integer array nums of length n.

// You start at index 0, and your goal is to reach index n - 1.

// From any index i, you may perform one of the following operations:

// Adjacent Step: Jump to index i + 1 or i - 1, if the index is within bounds.
// Prime Teleportation: If nums[i] is a prime number p, you may instantly jump to any index j != i such that nums[j] % p == 0.
// Return the minimum number of jumps required to reach index n - 1.

// Example 1:

// Input: nums = [1,2,4,6]

// Output: 2

// Explanation:

// One optimal sequence of jumps is:

// Start at index i = 0. Take an adjacent step to index 1.
// At index i = 1, nums[1] = 2 is a prime number. Therefore, we teleport to index i = 3 as nums[3] = 6 is divisible by 2.
// Thus, the answer is 2.

// Example 2:

// Input: nums = [2,3,4,7,9]

// Output: 2

// Explanation:

// One optimal sequence of jumps is:

// Start at index i = 0. Take an adjacent step to index i = 1.
// At index i = 1, nums[1] = 3 is a prime number. Therefore, we teleport to index i = 4 since nums[4] = 9 is divisible by 3.
// Thus, the answer is 2.

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <climits>

using namespace std;

class Solution
{
public:
    // isPrime[x] = true means x is prime
    vector<bool> isPrime;

    // SIEVE OF ERATOSTHENES
    //
    // Used to quickly check whether a number is prime or not
    //
    // Time Complexity:
    // O(n log log n)
    void buildPrimeSieve(int max_ele)
    {

        // initially assume all numbers are prime
        isPrime.resize(max_ele + 1, true);

        // 0 and 1 are not prime
        isPrime[0] = false;
        isPrime[1] = false;

        // mark multiples as non-prime
        for (int i = 2; i * i <= max_ele; i++)
        {

            // if still prime
            if (isPrime[i])
            {

                // mark all multiples of i as false
                for (int j = i * i; j <= max_ele; j += i)
                {

                    isPrime[j] = false;
                }
            }
        }
    }

    int minJumps(vector<int> &nums)
    {

        int n = nums.size();

        // map value -> all indices having that value
        //
        // Example:
        // nums = [2,4,2]
        //
        // mpp[2] = [0,2]
        // mpp[4] = [1]
        unordered_map<int, vector<int>> mpp;

        int max_ele = INT_MIN;

        // fill map and find maximum element
        for (int i = 0; i < n; i++)
        {

            mpp[nums[i]].push_back(i);

            max_ele = max(max_ele, nums[i]);
        }

        // build prime sieve till maximum value
        buildPrimeSieve(max_ele);

        // BFS queue
        queue<int> q;

        // visited[i] = whether index i already visited
        vector<bool> visited(n, false);

        // seen stores prime values already processed
        //
        // Important optimization
        //
        // Example:
        // if prime 2 already used once,
        // don't process multiples of 2 again
        unordered_set<int> seen;

        // start BFS from index 0
        q.push(0);

        visited[0] = true;

        int steps = 0;

        // STANDARD BFS
        while (!q.empty())
        {

            int size = q.size();

            // process one BFS level
            while (size--)
            {

                int u = q.front();
                q.pop();

                // reached last index
                if (u == n - 1)
                    return steps;

                // MOVE LEFT
                if (u - 1 >= 0 && (!visited[u - 1]))
                {

                    q.push(u - 1);

                    visited[u - 1] = true;
                }

                // MOVE RIGHT
                if (u + 1 <= n - 1 && (!visited[u + 1]))
                {

                    q.push(u + 1);

                    visited[u + 1] = true;
                }

                // PRIME TELEPORT LOGIC
                //
                // If nums[u] is NOT prime
                // OR already processed earlier
                //
                // then skip
                if ((!isPrime[nums[u]]) || seen.count(nums[u]))
                    continue;

                // if nums[u] is prime
                //
                // we can jump to indices having
                // multiples of nums[u]
                //
                // Example:
                //
                // nums[u] = 2
                //
                // can jump to indices containing:
                // 2,4,6,8,10...
                for (int multiple = nums[u];
                     multiple <= max_ele;
                     multiple += nums[u])
                {

                    // if this multiple not present in array
                    // skip
                    if (!mpp.contains(multiple))
                        continue;

                    // visit all indices having this multiple
                    for (auto &v : mpp[multiple])
                    {

                        if (!visited[v])
                        {

                            q.push(v);

                            visited[v] = true;
                        }
                    }
                }

                // mark this prime as already processed
                seen.insert(nums[u]);
            }

            // one BFS level completed
            steps++;
        }

        return steps;
    }
};

int main()
{

    Solution s;

    // SAMPLE INPUT
    //
    // Prime teleport explanation:
    //
    // from value 2
    // can jump to indices containing:
    // 2,4,6,8...
    vector<int> nums = {2, 4, 6, 3, 9, 12};

    int ans = s.minJumps(nums);

    cout << "Minimum Jumps = " << ans << endl;

    return 0;
}