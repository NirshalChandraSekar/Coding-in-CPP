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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length=0;
        ListNode* first = head;
        while(first){
            first = first->next;
            length++;
        }
        int remove = length-n;
        
        if(remove == 0) return head->next;

        ListNode* current = head;
        for(int i=0; i<remove-1; i++){
            current = current->next;
        }

        current->next = current->next->next;

        return head;
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

    // Removing the 2nd node from the end
    ListNode* modifiedHead = solution.removeNthFromEnd(head, 3);

    // Printing the modified linked list
    ListNode* current = modifiedHead;
    while(current){
        cout << current->val << " ";
        current = current->next;
    }
    
    // Freeing the allocated memory
    current = modifiedHead;
    while(current){
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
