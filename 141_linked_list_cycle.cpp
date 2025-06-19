#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next){

            fast = (fast->next)->next;
            slow = slow->next;
            
            if(fast == slow) return true;
        }
        return false;
    }
};

int main(){
    Solution solution;

    // Creating a linked list with a cycle: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = head->next; // Creating a cycle

    // Checking if the linked list has a cycle
    bool hasCycle = solution.hasCycle(head);

    cout << "Has cycle: " << (hasCycle ? "Yes" : "No") << endl;

    // Freeing the allocated memory (not possible in this case due to cycle)
    // In practice, you would need to break the cycle before freeing memory.

    return 0;
}