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
        bool isSameTree(TreeNode* p, TreeNode* q) {
            stack<pair<TreeNode*, TreeNode*>> mystack;
    
            mystack.push({p, q});
    
            while(mystack.size()>0){
                TreeNode* node1 = mystack.top().first;
                TreeNode* node2 = mystack.top().second;
                mystack.pop();
    
                if(!node1 && !node2) continue;
                if(!node1 || !node2) return false;
                if(node1->val != node2->val) return false;
    
                mystack.push({node1->left, node2->left});
                mystack.push({node1->right, node2->right});
            }
            return true;
        }
    };


int main() {
    // Example usage:
    TreeNode* tree1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* tree2 = new TreeNode(1, new TreeNode(2), new TreeNode(3));        
    Solution solution;
    bool result = solution.isSameTree(tree1, tree2);
    cout << (result ? "Trees are the same." : "Trees are not the same.") << endl;
}