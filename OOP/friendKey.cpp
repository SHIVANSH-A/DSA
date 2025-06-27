#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Chai
{
private:
    string teaName;
    int servings;

public:
    Chai(string name, int serve) : teaName(name), servings(serve) {}

    friend bool compareServings(const Chai &chai1, const Chai &chai2);
    //Same can be done using class

    void display() const
    {
        cout << "teaname: " << teaName << endl;
    }
};

bool compareServings(const Chai &chai1, const Chai &chai2)
{
    return chai1.servings > chai2.servings;
}

// class A {
// private:
//     int data = 5;

//     // Declare class B as a friend
//     friend class B;
// };

// class B {
// public:
//     void display(A obj) {
//         cout << "Accessing A's private data: " << obj.data << endl;
//     }
// };

int main()
{
    Chai masalaChai("Masala Chai", 14);
    Chai gingerChai("Ginger Chai", 8);

    masalaChai.display();
    gingerChai.display();

    if (compareServings(masalaChai, gingerChai))
    {
        cout << "Masal chai is having MORE servings" << endl;
    }
    else
    {
        cout << "Masal chai is having LESS servings" << endl;
    }
}