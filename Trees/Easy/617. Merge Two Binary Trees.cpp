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

// dfs Solution
// Time Complexity: O(n); max nodes in either tree
// Space Complexity: O(h) max height in either tree
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2)
            return nullptr;

        int val = (!root1 ? 0 : root1->val) + (!root2 ? 0 : root2->val);
        TreeNode *root = new TreeNode(val);

        root->left = mergeTrees(!root1 ? nullptr : root1->left,
                                !root2 ? nullptr : root2->left);

        root->right = mergeTrees(!root1 ? nullptr : root1->right,
                                 !root2 ? nullptr : root2->right);

        return root;
    }
};

// bfs solution
// Time Complexity: O(n)
// Space Complexity: O(h)

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1) return root2;
        if(!root2) return root1;

        queue<TreeNode*> q1;
        queue<TreeNode*> q2;

        q1.push(root1);
        q2.push(root2);

        while(!q1.empty() || !q2.empty()) {
            TreeNode *node1 = q1.front();
            TreeNode *node2 = q2.front();

            q1.pop();
            q2.pop();

            if(!node1 && !node2)
                continue;

            node1->val = (node1 ? node1->val : 0) + (node2 ? node2->val : 0);

            if(!(node1->left) && node2->left)
                node1->left = node2->left; //if node1 doesn't exist then point it to node2, no need to push it to queue
            else if(node1->left && node2->left) {
                q1.push(node1->left);
                q2.push(node2->left);
            }

            if(!(node1->right) && node2->right)
                node1->right = node2->right;
            else if(node1->right && node2->right) {
                q1.push(node1->right);
                q2.push(node2->right);
            }
        }
        return root1;
    }
};
