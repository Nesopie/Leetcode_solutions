/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Recursive Solution
// Time Complexity: O(n)
// Space Complexity: O(h)
class Solution {
public:
    static void helperPreorder(TreeNode* root, vector<int> &ans) {
        if(!root) return;
        ans.push_back(root->val);
        helperPreorder(root->left, ans);
        helperPreorder(root->right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        helperPreorder(root, ans);
        return ans;
    }
};

// Iterative Solution
// Time Complexity: O(n)
// Space Complexity: O(h)

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};

        stack<TreeNode*> preorder;
        vector<int> ans;

        preorder.push(root);

        while(!(preorder.empty())) {
            TreeNode *top = preorder.top();
            preorder.pop();

            ans.push_back(top->val);
            if(top->right) preorder.push(top->right);
            if(top->left) preorder.push(top->left);
        }
        return ans;
    }
};
