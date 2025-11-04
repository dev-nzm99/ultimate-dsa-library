/*
  Author:Nazmul Islam
  Created: 2025-12-06 11:45
*/
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to detect cycle in a linked list
bool hasCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true; // cycle found
        }
    }
    return false; // no cycle
}

int main() {
    // Create nodes
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Create a cycle:
    // Point the last node (5) to the 3rd node (value 3)
    head->next->next->next->next->next = head->next->next;

    // Now the list looks like:
    // 1 -> 2 -> 3 -> 4 -> 5
    //           ↑         |
    //           └─────────┘  (cycle)

    // Test for cycle
    if (hasCycle(head))
        cout << "Cycle detected" << endl;
    else
        cout << "No cycle" << endl;

    return 0;
}
