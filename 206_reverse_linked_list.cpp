#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* previous = nullptr;
        ListNode* current = head;

        while(current){
            ListNode* temp = current->next;
            current->next = previous;
            previous = current;
            current = temp;
        }
        return previous;
        
    }
};

int main() {
    Solution solution;
    
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    // Reversing the linked list
    ListNode* reversedHead = solution.reverseList(head);
    
    // Printing the reversed linked list
    ListNode* current = reversedHead;
    while(current){
        cout << current->val << " ";
        current = current->next;
    }
    
    // Freeing the allocated memory
    current = reversedHead;
    while(current){
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }
    
    return 0;
}