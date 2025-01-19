// mplement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

// Implement the MyStack class:

// void push(int x) Pushes element x to the top of the stack.
// int pop() Removes the element on the top of the stack and returns it.
// int top() Returns the element on the top of the stack.
// boolean empty() Returns true if the stack is empty, false otherwise.
// Notes:

// You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
// Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.

// Example 1:

// Input
// ["MyStack", "push", "push", "top", "pop", "empty"]
// [[], [1], [2], [], [], []]
// Output
// [null, null, null, 2, 2, false]

// Explanation
// MyStack myStack = new MyStack();
// myStack.push(1);
// myStack.push(2);
// myStack.top(); // return 2
// myStack.pop(); // return 2
// myStack.empty(); // return False
#include <bits/stdc++.h>
using namespace std;

int main()
{
    MyStack *obj = new MyStack();

    // Test the push operation
    obj->push(10);
    obj->push(20);
    obj->push(30);

    // Test the top operation
    cout << "Top element: " << obj->top() << endl; // Expected: 30

    // Test the pop operation
    cout << "Popped element: " << obj->pop() << endl; // Expected: 30

    // Test the top operation again
    cout << "Top element after pop: " << obj->top() << endl; // Expected: 20

    // Test the empty operation
    cout << "Is stack empty? " << (obj->empty() ? "Yes" : "No") << endl; // Expected: No

    // Pop remaining elements
    cout << "Popped element: " << obj->pop() << endl; // Expected: 20
    cout << "Popped element: " << obj->pop() << endl; // Expected: 10

    // Test the empty operation after all elements are popped
    cout << "Is stack empty after all pops? " << (obj->empty() ? "Yes" : "No") << endl; // Expected: Yes

    delete obj;
    return 0;
}
class MyStack
{
public:
    queue<int> temp;
    queue<int> mainq;
    MyStack()
    {
    }

    void push(int x)
    {
        temp.push(x);

        while (!mainq.empty())
        {
            temp.push(mainq.front());
            mainq.pop();
        }
        swap(temp, mainq);
    }

    int pop()
    {
        int ele = mainq.front();
        mainq.pop();
        return ele;
    }

    int top()
    {
        return mainq.front();
    }

    bool empty()
    {
        return mainq.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */