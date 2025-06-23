#include <stack>
#include <iostream>
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
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> stack_;

        if(!root) return nullptr;

        stack_.push(root);

        while(stack_.size() > 0){
            TreeNode* node = stack_.top();
            stack_.pop();
            TreeNode* temp = node->right;
            node->right = node->left;
            node->left = temp;

            if(node->left) stack_.push(node->left);
            if(node->right) stack_.push(node->right);
        }

        return root;
    }
};

int main() {
    Solution solution;

    // Creating a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Inverting the binary tree
    TreeNode* invertedRoot = solution.invertTree(root);

    // Printing the inverted tree (pre-order traversal)
    stack<TreeNode*> stack_;
    stack_.push(invertedRoot);
    while (!stack_.empty()) {
        TreeNode* node = stack_.top();
        stack_.pop();
        if (node) {
            cout << node->val << " ";
            stack_.push(node->right); // right child first
            stack_.push(node->left);  // left child second
        }
    }
    cout << endl;

    return 0;
}