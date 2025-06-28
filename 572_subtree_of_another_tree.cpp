#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool Sametree(TreeNode* root1, TreeNode* root2){
        stack<pair<TreeNode*, TreeNode*>> stack_;
        stack_.push({root1, root2});
        while(stack_.size()>0){
            TreeNode* node1 = stack_.top().first;
            TreeNode* node2 = stack_.top().second;
            stack_.pop();

            if(!node1 && !node2) continue;
            if(!node1 || !node2) return false;
            if(node1->val != node2->val) return false;

            stack_.push({node1->left, node2->left});
            stack_.push({node1->right, node2->right});
        }
        return true;

    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return true;
        if(!root && subRoot) return false;
        if(root && !subRoot) return true;
        
        stack<TreeNode*> mystack;
        mystack.push(root);
        while(mystack.size()>0){
            TreeNode* node = mystack.top();
            mystack.pop();
            if(node->val == subRoot->val && Sametree(node, subRoot)) return true;
            
            if(node->left) mystack.push(node->left);
            if(node->right) mystack.push(node->right);
        }
        return false;
    }
};

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    TreeNode* subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    Solution solution;
    cout << "Is subRoot a subtree of root? " << (solution.isSubtree(root, subRoot) ? "Yes" : "No") << endl;

    // Clean up memory (not shown here)
    return 0;
}