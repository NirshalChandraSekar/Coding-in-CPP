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
    int max_dia = 0;

    int find_dia(TreeNode* root){
        if(!root) return 0;

        int left = find_dia(root->left);
        int right = find_dia(root->right);

        max_dia = max(max_dia, left + right);

        return max(left,right) + 1;            
    }

    int diameterOfBinaryTree(TreeNode* root) {
        
        find_dia(root);

        return max_dia;
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
    cout << "Diameter of the binary tree: " << solution.diameterOfBinaryTree(root) << endl;

    // Clean up memory (not shown here)
    return 0;
}
