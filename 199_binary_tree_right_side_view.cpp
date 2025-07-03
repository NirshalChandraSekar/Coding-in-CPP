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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> final_list;
        if(!root) return final_list;

        int level = 0;
        stack<pair<TreeNode*, int>> mystack;
        mystack.push({root, level});

        while(mystack.size() > 0){
            TreeNode* node = mystack.top().first;
            int stage = mystack.top().second;
            mystack.pop();

            if(stage < final_list.size()) final_list[stage] = node->val;
            else final_list.push_back(node->val);

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
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution solution;
    vector<int> result = solution.rightSideView(root);

    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}