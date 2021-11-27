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

// dfs solution using recursive stack
// Time Complexity: O(n)
// Space Complexity: O(h)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;

        root->left = invertTree(root->left);
        root->right = invertTree(root->right);

        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        return root;
    }
};

// dfs solution using stack
// Time Complexity: O(n)
// Space Complexity: O(h)

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            TreeNode* left = node->left;
            node->left = node->right;
            node->right = left;

            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);
        }

        return root;
    }
};

// bfs Solution
// Time Complexity: O(n)
// Space Complexity: O(max number of nodes in a level)

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode *node = q.front();
            q.pop();

            TreeNode *left = node->left;
            node->left = node->right;
            node->right = left;

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return root;
    }
};
