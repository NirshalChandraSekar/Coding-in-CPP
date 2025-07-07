#include <iostream>
#include <stack>
#include <tuple>
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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;

        long long left_boundary = LLONG_MIN;
        long long right_boundary = LLONG_MAX;

        stack<tuple<TreeNode*, long long, long long>> mystack;
        mystack.push({root, left_boundary, right_boundary});

        while(mystack.size() > 0){
            auto top = mystack.top();
            mystack.pop();

            TreeNode* node = get<0>(top);
            long long left = get<1>(top);
            long long right = get<2>(top);;

            if(node->val <= left || node->val >= right) return false;

            if(node->left) mystack.push({node->left, left, node->val});

            if(node->right) mystack.push({node->right, node->val, right});
        }

        return true;
    }
};

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    Solution solution;
    bool result = solution.isValidBST(root);

    cout << "Is the tree a valid BST? " << (result ? "Yes" : "No") << endl;

    // Clean up memory
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}