#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to reverse the linked list
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;  // Previous node (initially null)
    ListNode* current = head;  // Current node to process
    ListNode* next = nullptr;  // Next node to keep track of the list

    while (current != nullptr) {
        next = current->next;  // Store the next node
        current->next = prev;  // Reverse the pointer
        prev = current;        // Move `prev` forward
        current = next;        // Move `current` forward
    }

    return prev;  // `prev` is the new head of the reversed list
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example usage
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    // Reverse the linked list
    ListNode* reversedHead = reverseList(head);

    cout << "Reversed List: ";
    printList(reversedHead);

    return 0;
}
