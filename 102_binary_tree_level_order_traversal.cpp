#include <vector>
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
        vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int>> final_list;
            int level = 0;
            
            if(!root) return final_list;
    
    
            stack<pair<TreeNode*, int>> mystack;
            mystack.push({root, level});
    
            while(mystack.size()>0){
                TreeNode* node = mystack.top().first;
                int stage = mystack.top().second;
                mystack.pop();
    
                if(stage < final_list.size()) final_list[stage].push_back(node->val);
                else final_list.push_back({node->val});
    
                if(node->right) mystack.push({node->right, stage+1});
                if(node->left) mystack.push({node->left, stage+1});
            }
    
            return final_list;
    
        }
    };


int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    Solution solution;
    vector<vector<int>> result = solution.levelOrder(root);
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
}