// You are given an integer side, representing the edge length of a square with corners at (0, 0), (0, side), (side, 0), and (side, side) on a Cartesian plane.

// You are also given a positive integer k and a 2D integer array points, where points[i] = [xi, yi] represents the coordinate of a point lying on the boundary of the square.

// You need to select k elements among points such that the minimum Manhattan distance between any two points is maximized.

// Return the maximum possible minimum Manhattan distance between the selected k points.

// The Manhattan Distance between two cells (xi, yi) and (xj, yj) is |xi - xj| + |yi - yj|.

// Brute force (binary search + backtracking)
//  class Solution {
//  public:

//     // Function to compute Manhattan Distance between two points
//     // Manhattan Distance = |x1 - x2| + |y1 - y2|
//     int manhattanDist(vector<int> &p1, vector<int> &p2){
//         return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
//     }

//     /*
//     INTUITION FOR check():
//     ----------------------
//     We are trying to pick k points such that:
//     -> The minimum distance between ANY pair of chosen points >= mid

//     This is a BACKTRACKING problem:
//     - Try picking points one by one
//     - For each new point, check if it satisfies the condition with all already chosen points
//     - If yes → include it and continue
//     - If not → skip it

//     If at any point we successfully pick k points → return true
//     */

//     bool check(vector<vector<int>>& points, int k, int mid, int i, vector<int>& chosen){

//         // Base Case: If we already selected k points, condition satisfied
//         if(chosen.size() == k){
//             return true;
//         }

//         // Try picking points starting from index i
//         for(int p = i; p < points.size(); p++){

//             bool valid = true;

//             // Check if current point maintains minimum distance >= mid
//             // with all previously chosen points
//             for(int idx : chosen){
//                 if(manhattanDist(points[p], points[idx]) < mid){
//                     valid = false;
//                     break;
//                 }
//             }

//             // If this point violates the condition, skip it
//             if(!valid){
//                 continue;
//             }

//             // Choose this point
//             chosen.push_back(p);

//             // Recursively try to pick remaining points
//             if(check(points, k, mid, p + 1, chosen)){
//                 return true; // Found valid selection
//             }

//             // Backtrack (undo the choice)
//             chosen.pop_back();
//         }

//         // No valid selection found
//         return false;
//     }

//     /*
//     INTUITION FOR maxDistance():
//     ---------------------------
//     We want to MAXIMIZE the minimum Manhattan distance.

//     Key idea:
//     -> If a distance 'mid' is possible, then all smaller distances are also possible.
//        (Monotonic property)

//     So we can apply BINARY SEARCH on the answer.

//     Search Space:
//     -> Minimum distance = 0
//     -> Maximum distance = 2 * side (max Manhattan distance on square boundary)

//     Process:
//     - Try a middle value (mid)
//     - Use check() to see if we can pick k points with at least 'mid' distance
//     - If YES → try bigger distance (move right)
//     - If NO → try smaller distance (move left)
//     */

//     int maxDistance(int side, vector<vector<int>>& points, int k) {

//         int l = 0;             // minimum possible distance
//         int r = 2 * side;      // maximum possible Manhattan distance
//         int result = 0;

//         while(l <= r){
//             int mid = l + (r - l) / 2;

//             vector<int> chosen; // stores indices of selected points

//             // Check if we can maintain minimum distance = mid
//             if(check(points, k, mid, 0, chosen)){
//                 result = mid;   // valid answer found
//                 l = mid + 1;    // try for a larger distance
//             }
//             else{
//                 r = mid - 1;    // reduce distance
//             }
//         }

//         return result;
//     }
// };

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef long long ll;

    ll convert(int side, int x, int y)
    {
        if (y == 0)
            return x;
        if (x == side)
            return side + y;
        if (y == side)
            return 3LL * side - x;
        return 4LL * side - y;
    }

    bool check(vector<ll> &doubled, int side, int k, int n, int mid)
    {
        ll perimeter = 4LL * side;

        for (int i = 0; i < n; i++)
        {
            int count = 1;
            int idx = i;
            ll lastPosition = doubled[idx];

            for (int j = 2; j <= k; j++)
            {
                ll target = lastPosition + mid;

                auto it = lower_bound(
                    doubled.begin() + idx + 1,
                    doubled.begin() + i + n,
                    target);

                if (it == doubled.begin() + i + n)
                {
                    break;
                }

                idx = it - doubled.begin();
                lastPosition = doubled[idx];
                count++;
            }

            if (count == k && (doubled[i] + perimeter - lastPosition) >= mid)
            {
                return true;
            }
        }

        return false;
    }

    int maxDistance(int side, vector<vector<int>> &points, int k)
    {

        ll perimeter = 4LL * side;
        int n = points.size();

        vector<ll> positions(n);
        for (int i = 0; i < n; i++)
        {
            positions[i] = convert(side, points[i][0], points[i][1]);
        }

        sort(positions.begin(), positions.end());

        vector<ll> doubled(2 * n);
        for (int i = 0; i < n; i++)
        {
            doubled[i] = positions[i];
            doubled[i + n] = positions[i] + perimeter;
        }

        int l = 0;
        int r = 2 * side;
        int result = 0;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (check(doubled, side, k, n, mid))
            {
                result = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;

    int side = 10;
    vector<vector<int>> points = {
        {0, 0},
        {10, 0},
        {10, 10},
        {0, 10},
        {5, 0},
        {10, 5}};

    int k = 3;

    int ans = sol.maxDistance(side, points, k);

    cout << "Maximum minimum distance: " << ans << endl;

    return 0;
}