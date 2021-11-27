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
    static void inorderHelper(TreeNode* root, vector<int> &ans) {
        if(!root) return;
        inorderHelper(root->left, ans);
        ans.push_back(root->val);
        inorderHelper(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorderHelper(root, ans);
        return ans;
    }
};

// Iterative solution
// Time Complexity: O(n)
// Space Complexity: O(h)

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};

        stack<TreeNode*> inorder;
        vector<int> ans;

        TreeNode* curr = root;

        while(curr || !(inorder.empty())) {
            while(curr) {
                inorder.push(curr);
                curr = curr->left;
            }

            curr = inorder.top();
            inorder.pop();

            ans.push_back(curr->val);

            curr = curr->right;
        }

        return ans;
    }
};
