#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0); // Dummy node to simplify result handling
        ListNode* current = dummyHead;
        int carry = 0;
        
        while (l1 || l2 || carry) {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            
            // Calculate the sum and carry
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            
            // Move to the next nodes
            current = current->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        
        return dummyHead->next;
    }
};

// Helper function to print a linked list
void printList(ListNode* node) {
    while (node) {
        cout << node->val;
        if (node->next) cout << " -> ";
        node = node->next;
    }
    cout << endl;
}

// Example usage
int main() {
    // Representing number 342 as 2 -> 4 -> 3
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    // Representing number 465 as 5 -> 6 -> 4
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    
    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);
    
    // Print the result: 7 -> 0 -> 8
    printList(result);
    
    return 0;
}
