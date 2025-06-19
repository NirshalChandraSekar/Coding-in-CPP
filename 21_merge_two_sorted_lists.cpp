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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* node = &dummy;

        while(list1 && list2){
            if(list1->val < list2->val){
                node->next = list1;
                list1 = list1->next;
            }
            else{
                node->next = list2;
                list2 = list2->next;
            }

            node = node->next;
        } 

        if(list1) node->next = list1;
        if(list2) node->next = list2;

        return dummy.next;
    }
};

int main() {
    Solution solution;

    // Creating two sorted linked lists: 1 -> 2 -> 4 and 1 -> 3 -> 4
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    // Merging the two sorted linked lists
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);

    // Printing the merged linked list
    ListNode* current = mergedList;
    while(current){
        cout << current->val << " ";
        current = current->next;
    }

    // Freeing the allocated memory
    current = mergedList;
    while(current){
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}