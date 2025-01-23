// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list in reverse.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *result = new ListNode(0);
        ListNode *curr = result;
        int carry = 0;

        while (l1 != NULL || l2 != NULL)
        {
            int sum = carry;

            if (l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            sum = sum % 10;

            curr->next = new ListNode(sum);
            curr = curr->next;
        }

        if (carry == 1)
        {
            curr->next = new ListNode(1);
        }

        return result->next;
    }
};

// Helper function to print a linked list
void printList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // Create two linked lists for testing
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    // Create an instance of the Solution class
    Solution solution;

    // Add the two linked lists
    ListNode *result = solution.addTwoNumbers(l1, l2);

    // Print the resulting linked list
    cout << "Result: ";
    printList(result);

    return 0;
}
#include <bits/stdc++.h>
// using namespace std;

// // Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

// class Solution {
// public:
//     int addTwoNumbers(ListNode* l1, ListNode* l2) {
//         int num1 = calculateNumber(l1);
//         int num2 = calculateNumber(l2);
//         return num1 + num2;
//     }

//     int calculateNumber(ListNode* node) {
//         if (!node) return 0;
//         return node->val  + calculateNumber(node->next)*10;
//     }
// };

// // Helper function to create a linked list from an array
// ListNode* createLinkedList(const vector<int>& nums) {
//     ListNode* head = nullptr;
//     ListNode* tail = nullptr;
//     for (int num : nums) {
//         if (!head) {
//             head = new ListNode(num);
//             tail = head;
//         } else {
//             tail->next = new ListNode(num);
//             tail = tail->next;
//         }
//     }
//     return head;
// }

// // Main function to test the Solution
// int main() {
//     // Create two linked lists
//     vector<int> list1 = {2, 4, 3}; // Represents the number 342
//     vector<int> list2 = {5, 6, 4}; // Represents the number 465

//     ListNode* l1 = createLinkedList(list1);
//     ListNode* l2 = createLinkedList(list2);

//     // Create an instance of the Solution class
//     Solution solution;

//     // Call the addTwoNumbers function
//     int result = solution.addTwoNumbers(l1, l2);

//     // Print the result
//     cout << "Sum of the two numbers: " << result << endl;

//     // Free the allocated memory
//     delete l1;
//     delete l2;

//     return 0;
// }
