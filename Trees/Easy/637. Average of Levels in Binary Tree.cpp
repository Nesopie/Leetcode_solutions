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

// bfs Solution
// Time Complexity: O(n)
// Space Complexity: O(max number of nodes in a level)

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;

        q.push(root);

        while(!(q.empty())) {
            int n = q.size();
            double sum = 0;

            for(int i = 0; i < n; i++) {
                TreeNode* currentNode = q.front();
                q.pop();

                sum += currentNode->val;

                if(currentNode->left) q.push(currentNode->left);
                if(currentNode->right) q.push(currentNode->right);
            }

            ans.push_back((double)(sum/n));
        }

        return ans;
    }
};
