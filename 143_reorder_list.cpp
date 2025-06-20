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
    void reorderList(ListNode* head) {
        ListNode* length_head = head;
        int length = 0;
        while(length_head){
            length_head = length_head->next;
            length += 1;
        }

        int mid = int(length/2);

        ListNode* second_head = head;
        for(int i=0; i<mid; i++) second_head = second_head->next;

        // reverse the second part of the list
        ListNode* previous = nullptr;
        while(second_head){
            ListNode* temp = second_head->next;
            second_head->next = previous;
            previous = second_head;
            second_head = temp;
        }
        second_head = previous;

        while(second_head){
            ListNode* temp1 = head->next;
            ListNode* temp2 = second_head->next;
            head->next = second_head;
            second_head->next = temp1;
            head = temp1;
            second_head = temp2;
        }

        if(head) head->next = nullptr;
    
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

    // Reordering the linked list
    solution.reorderList(head);

    // Printing the reordered linked list
    ListNode* current = head;
    while(current) {
        cout << current->val << " ";
        current = current->next;
    }
    
    // Freeing the allocated memory
    current = head;
    while(current) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}