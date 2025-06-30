#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

 class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            while(root){
                if((root->val >= p->val && root->val <= q->val) || (root->val <= p->val && root->val >= q->val)) return root; //split detected
                else if(root->val < p->val && root->val < q->val) root = root->right;
                else if(root->val > p->val && root->val > q->val) root = root->left;
            }
            return nullptr;
        }
    };



int main() {
    // Example usage:
    TreeNode* root = new TreeNode(6);
    TreeNode* p = new TreeNode(2);  
    TreeNode* q = new TreeNode(8);
    root->left = p;
    root->right = q;
    p->left = new TreeNode(0);
    p->right = new TreeNode(4);
    p->right->left = new TreeNode(3);
    p->right->right = new TreeNode(5);
    q->left = new TreeNode(7);
    q->right = new TreeNode(9);
    Solution solution;
    TreeNode* ancestor = solution.lowestCommonAncestor(root, p, q);
    if (ancestor) {
        cout << "Lowest Common Ancestor: " << ancestor->val << endl;
    } else {
        cout << "No common ancestor found." << endl;
    }
}