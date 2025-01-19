// Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

// Implement the MyQueue class:

// void push(int x) Pushes element x to the back of the queue.
// int pop() Removes the element from the front of the queue and returns it.
// int peek() Returns the element at the front of the queue.
// boolean empty() Returns true if the queue is empty, false otherwise.
// Notes:

// You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
// Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.

// Example 1:

// Input
// ["MyQueue", "push", "push", "peek", "pop", "empty"]
// [[], [1], [2], [], [], []]
// Output
// [null, null, null, 1, 1, false]

// Explanation
// MyQueue myQueue = new MyQueue();
// myQueue.push(1); // queue is: [1]
// myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
// myQueue.peek(); // return 1
// myQueue.pop(); // return 1, queue is [2]
// myQueue.empty(); // return false
class MyQueue
{
public:
    stack<int> temp;
    stack<int> mainstk;
    MyQueue()
    {
    }

    void push(int x)
    {
        while (!mainstk.empty())
        {
            temp.push(mainstk.top());
            mainstk.pop();
        }
        mainstk.push(x);
        while (!temp.empty())
        {
            mainstk.push(temp.top());
            temp.pop();
        }
    }

    int pop()
    {
        int ele = mainstk.top();
        mainstk.pop();
        return ele;
    }

    int peek()
    {
        return mainstk.top();
    }

    bool empty()
    {
        return mainstk.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    MyQueue *obj = new MyQueue();

    // Test the push operation
    obj->push(10);
    obj->push(20);
    obj->push(30);

    // Test the peek operation
    cout << "Front element: " << obj->peek() << endl; // Expected: 10

    // Test the pop operation
    cout << "Popped element: " << obj->pop() << endl; // Expected: 10

    // Test the peek operation again
    cout << "Front element after pop: " << obj->peek() << endl; // Expected: 20

    // Test the empty operation
    cout << "Is queue empty? " << (obj->empty() ? "Yes" : "No") << endl; // Expected: No

    // Pop remaining elements
    cout << "Popped element: " << obj->pop() << endl; // Expected: 20
    cout << "Popped element: " << obj->pop() << endl; // Expected: 30

    // Test the empty operation after all elements are popped
    cout << "Is queue empty after all pops? " << (obj->empty() ? "Yes" : "No") << endl; // Expected: Yes

    delete obj;
    return 0;
}
