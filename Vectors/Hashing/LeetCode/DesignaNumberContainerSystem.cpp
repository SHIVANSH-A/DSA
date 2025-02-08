// Design a number container system that can do the following:

// Insert or Replace a number at the given index in the system.
// Return the smallest index for the given number in the system.
// Implement the NumberContainers class:

// NumberContainers() Initializes the number container system.
// void change(int index, int number) Fills the container at index with the number. If there is already a number at that index, replace it.
// int find(int number) Returns the smallest index for the given number, or -1 if there is no index that is filled by number in the system.
#include <bits/stdc++.h>
using namespace std;

int main() {
    NumberContainers nc;

    nc.change(1, 10);
    nc.change(2, 10);
    nc.change(3, 20);

    cout << "Find 10: " << nc.find(10) << endl; // Should return 1 (smallest index with number 10)
    cout << "Find 20: " << nc.find(20) << endl; // Should return 3
    cout << "Find 30: " << nc.find(30) << endl; // Should return -1 (not found)

    nc.change(1, 20);
    cout << "Find 10: " << nc.find(10) << endl; // Should return 2
    cout << "Find 20: " << nc.find(20) << endl; // Should return 1

    return 0;
}
class NumberContainers {
    public:
        NumberContainers() {
        }
    
        void change(int index, int number) {
            if (d.find(index)!=d.end()) {
                int oldNumber = d[index];
                g[oldNumber].erase(index);
                if (g[oldNumber].empty()) {
                    g.erase(oldNumber);
                }
            }
            d[index] = number;
            g[number].insert(index);
        }
    
        int find(int number) {
            return (g.find(number)!=g.end()) ? *g[number].begin() : -1;
        }
    
    private:
        unordered_map<int, int> d;
        unordered_map<int, set<int>> g;
    };