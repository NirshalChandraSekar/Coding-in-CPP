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
    bool balanced = true;
    int check(TreeNode* node){
        if(!node) return 0;

        int left = check(node->left);
        int right = check(node->right);

        if(abs(left-right) > 1) balanced = false;

        return max(left, right) + 1;

    }

    bool isBalanced(TreeNode* root) {
        check(root);
        return balanced;
    }
};

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    cout << "Is the binary tree balanced? " << (solution.isBalanced(root) ? "Yes" : "No") << endl;

    // Clean up memory (not shown here)
    return 0;
}