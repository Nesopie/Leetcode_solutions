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

// Recursive solution
// Time Complexity: O(n)
// Space Complexity: O(h)

class Solution {
public:
    static void postorderHelper(TreeNode* root, vector<int> &ans) {
        if(!root) return;
        postorderHelper(root->left, ans);
        postorderHelper(root->right, ans);
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorderHelper(root, ans);
        return ans;
    }
};

// Iterative Solution
// Time Complexity: O(n)
// Space Complexity: O(h)

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> postorder;
        vector<int> ans;

        TreeNode *curr = root;

        while(curr || !(postorder.empty())) {
            if(curr) {
                postorder.push(curr);
                curr = curr->left;
                // Keep pushing till the left child is null
            }else {
                TreeNode *temp = (postorder.top())->right;
                if(!temp) {
                    // If there is no right child then push_back into the ans
                    temp = postorder.top();
                    postorder.pop();

                    ans.push_back(temp->val);
                    // Keep pushing back until the temp node is the parent's right child
                    while(!(postorder.empty()) && temp == (postorder.top()->right)) {
                        temp = postorder.top();
                        postorder.pop();
                        ans.push_back(temp->val);
                    }
                }else {
                    // If there is a right child then repeat the process again with curr node
                    // as the right child
                    curr = temp;
                }
            }
        }

        return ans;
    }
};
