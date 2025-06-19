#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // practice to insert a new node between 3 and 4

    ListNode* return_head = head;

    while(true){
        if(head->val == 3){
            break;
        }
        head = head->next;
    }

    ListNode* new_node = new ListNode(100);
    new_node->next = head->next;
    head->next = new_node;

    while(return_head){
        cout << return_head->val << " ";
        return_head = return_head->next;
    }
    return 0;
    
}
