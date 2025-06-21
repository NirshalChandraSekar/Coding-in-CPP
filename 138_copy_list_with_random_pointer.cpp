#include <unordered_map>
#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        unordered_map<Node*, Node*> old2new;
        Node* first = head;
        Node* copy_head = new Node(head->val);
        Node* second = copy_head;
        while(first && first->next) {
            second->next = new Node(first->next->val);
            old2new[first] = second;
            first = first->next;
            second = second->next;
        }
        old2new[first] = second; // for the last node
        
        for(auto pair : old2new){
            if(pair.first->random) {
                pair.second->random = old2new[pair.first->random];
            } else {
                pair.second->random = NULL;
            }
        }

        return copy_head;

    }
};

int main() {
    Solution solution;

    // Creating a linked list with random pointers
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->random = head->next; // 1's random points to 2
    head->next->random = head; // 2's random points to 1
    head->next->next->random = head->next; // 3's random points to 2

    // Copying the linked list
    Node* copiedList = solution.copyRandomList(head);

    // Printing the original linked list
    while(head) {
        cout << "Value: " << head->val;
        if (head->random) {
            cout << ", Random Value: " << head->random->val;
        } else {
            cout << ", Random Value: NULL";
        }
        cout << endl;
        head = head->next;
    }

    // Printing the copied linked list
    Node* current = copiedList;
    while(current) {
        cout << "Value: " << current->val;
        if (current->random) {
            cout << ", Random Value: " << current->random->val;
        } else {
            cout << ", Random Value: NULL";
        }
        cout << endl;
        current = current->next;
    }

    return 0;
}



