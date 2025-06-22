#include <iostream>
using namespace std;

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
        int carry = 0;
        ListNode* head = new ListNode(0);
        ListNode* iter = head;
        while(l1 || l2 || carry){
            int sum = carry;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            carry = int(sum/10);
            iter->next = new ListNode(sum%10);
            iter = iter->next;
        }
        return head->next;
    }
};

int main() {
    Solution solution;

    // Creating two linked lists representing the numbers 342 and 465
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3))); // Represents 342
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4))); // Represents 465

    // Adding the two numbers
    ListNode* result = solution.addTwoNumbers(l1, l2);

    // Printing the result
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}