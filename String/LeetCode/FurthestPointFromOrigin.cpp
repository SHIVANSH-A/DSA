// You are given a string moves of length n consisting only of characters 'L', 'R', and '_'. The string represents your movement on a number line starting from the origin 0.

// In the ith move, you can choose one of the following directions:

// move to the left if moves[i] = 'L' or moves[i] = '_'
// move to the right if moves[i] = 'R' or moves[i] = '_'
// Return the distance from the origin of the furthest point you can get to after n moves.
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution
{
public:
    int furthestDistanceFromOrigin(string moves)
    {
        int l = 0, r = 0, blank = 0;

        for (auto i : moves)
        {
            if (i == 'L')
                l++;
            else if (i == 'R')
                r++;
            else
                blank++;
        }

        return blank + abs(r - l);
    }
};

// class Solution {
// public:
//     int furthestDistanceFromOrigin(string moves) {
//         int l=0,r=0,blank=0;

//         for(auto i:moves){
//             if(i=='L')l++;
//             else if(i=='R') r++;
//             else blank++;
//         }

//         return blank+abs(r-l);
//     }
// };

int main()
{
    Solution obj;

    string moves;
    cout << "Enter moves string: ";
    cin >> moves;

    int result = obj.furthestDistanceFromOrigin(moves);

    cout << "Furthest Distance from Origin: " << result << endl;

    return 0;
}