#include <stack>
#include <iostream>
#include <math.h>
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
    int goodNodes(TreeNode* root) {
        int good_nodes = 0;

        if(!root) return good_nodes;

        stack<pair<TreeNode*, int>> mystack;

        mystack.push({root, root->val});

        while(mystack.size() > 0){
            TreeNode* root = mystack.top().first;
            int max_history = mystack.top().second;
            mystack.pop();

            int max_val = max(root->val, max_history);

            if(root->val >= max_val) good_nodes++;

            if(root->left) mystack.push({root->left, max_val});

            if(root->right) mystack.push({root->right, max_val});
        }

        return good_nodes;
    }
};

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);

    Solution solution;
    int result = solution.goodNodes(root);

    cout << "Number of good nodes: " << result << endl;

    // Clean up memory
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}