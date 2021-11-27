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

// Iterator solution
// Time Complexity: O(h)
// Space Complexity: O(1)
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return root;

        TreeNode* treeIterator = root;

        while(treeIterator) {
            if(treeIterator->val < val) {
                treeIterator = treeIterator->right;
            }else if(treeIterator->val > val) {
                treeIterator = treeIterator->left;
            }else {
                return treeIterator;
            }
        }

        return nullptr;
    }
};

// Recursive Solution
// Time Complexity: O(h)
// Space Complexity: O(h)

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return root;
        if(root->val == val) return root;
        else if(root->val < val) return searchBST(root->right, val);
        else return searchBST(root->left, val);
    }
};
