// There is a circle of red and blue tiles. You are given an array of integers colors and an integer k. The color of tile i is represented by colors[i]:

// colors[i] == 0 means that tile i is red.
// colors[i] == 1 means that tile i is blue.
// An alternating group is every k contiguous tiles in the circle with alternating colors (each tile in the group except the first and last one has a different color from its left and right tiles).

// Return the number of alternating groups.

// Note that since colors represents a circle, the first and the last tiles are considered to be next to each other.
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    std::vector<int> colors = {1, 2, 1, 2, 1}; // Example input
    int k = 3;                                 // Example k value

    int count = 0;
    int length = 1;
    int curr = colors[0];

    for (int i = 1; i < colors.size(); i++)
    {
        if (colors[i] == curr)
        {
            curr = colors[i];
            length = 1;
            continue;
        }
        length++;
        curr = colors[i];
        if (length >= k)
            count++;
    }

    for (int i = 0; i < k - 1; i++)
    {
        if (colors[i] == curr)
        {
            break;
        }
        length++;
        curr = colors[i];
        if (length >= k)
            count++;
    }

    std::cout << "Number of alternating groups: " << count << std::endl;
    return 0;
}
class Solution
{
public:
    int numberOfAlternatingGroups(vector<int> &colors, int k)
    {
        int count = 0;
        // colors.insert(colors.end(),colors.begin(),colors.begin()+k-1);
        // int i=0;
        // int j=1;

        // for(int k:colors){
        //     cout<<k<<" ";
        // }
        // while(j<colors.size()){
        //     if(colors[j]==colors[j-1]){
        //         i++;
        //         count=0;
        //     }
        //     if(j-i+1==k){
        //         count++;
        //         i++;
        //         j=i+1;
        //     }
        //     j++;
        // }

        int length = 1;
        int curr = colors[0];

        for (int i = 1; i < colors.size(); i++)
        {
            if (colors[i] == curr)
            {
                curr = colors[i];
                length = 1;
                continue;
            }
            length++;
            curr = colors[i];
            if (length >= k)
                count++;
        }

        for (int i = 0; i < k - 1; i++)
        {
            if (colors[i] == curr)
            {
                break;
            }
            length++;
            curr = colors[i];
            if (length >= k)
                count++;
        }

        // int count = 0;
        // int n = colors.size();

        // for(int i = 0; i < n; i++) {
        //     bool flag = true;

        //     for(int j = 1; j < k; j++) {
        //         int prev = (i + j - 1) % n;
        //         int curr = (i + j) % n;

        //         if (colors[prev] == colors[curr]) {
        //             flag = false;
        //             break;
        //         }
        //     }

        //     if (flag) count++;
        // }
        return count;
    }
};
