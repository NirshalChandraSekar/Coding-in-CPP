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
    int maxDepth(TreeNode* root) {
        int max_depth = 0;
        stack<pair<TreeNode*, int>> mystack;

        if(!root) return 0;

        mystack.push({root, 1});

        while(mystack.size() > 0){
            TreeNode* node = mystack.top().first;
            int depth = mystack.top().second;
            mystack.pop();

            if(max_depth < depth) max_depth = depth;

            if(node->left) mystack.push({node->left, depth+1});
            if(node->right) mystack.push({node->right, depth+1});
        }

        return max_depth;
    }
};

int main(){
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    cout << "Maximum depth of the binary tree: " << solution.maxDepth(root) << endl;

    // Clean up memory (not shown here)
    return 0;
}