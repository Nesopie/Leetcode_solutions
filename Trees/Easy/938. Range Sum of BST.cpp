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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        if(root->val < low) return rangeSumBST(root->right, low, high);
        if(root->val > high) return rangeSumBST(root->left, low, high);
        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};

// Iterative solution
// Time Complexity: O(n)
// Space Complexity: O(h)

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        stack<TreeNode*> st;
        st.push(root);

        int rangeSum = 0;

        while(!st.empty()) {
            TreeNode *node = st.top();
            st.pop();
            if(!node) continue;
            // don't do if node->val < low push node->right
            // and if node->val > high push node->left
            // if the range is 7 and 15 and the node is 10
            // and if you do the above steps then nothing will be pushed on to
            // the stack as you will only push non range members on the stack
            // whereas if you use the below conditions you can push the non range
            // and range values 
            if(node->val > low) st.push(node->left);
            if(node->val < high) st.push(node->right);

            if(node->val >= low && node->val <= high) rangeSum += node->val;
        }

        return rangeSum;
    }
};
