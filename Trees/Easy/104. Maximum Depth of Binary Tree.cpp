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

// dfs solution
// Time Complexity: O(n)
// Space Complexity: O(h)

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

// bfs Solution
// Time Complexity: O(n)
// Space Complexity: O(max number of nodes in a level)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int maxDepth = INT_MIN;

        queue<pair<TreeNode*, int> > q;
        q.push(make_pair(root, 1));

        while(!(q.empty())) {
            pair<TreeNode*, int> nodePair = q.front();
            q.pop();

            TreeNode* node = nodePair.first;
            maxDepth = max(maxDepth, nodePair.second);
            if(node->left) q.push(make_pair(node->left, nodePair.second + 1));
            if(node->right) q.push(make_pair(node->right, nodePair.second + 1));
        }

        return maxDepth;
    }
};

// bfs solution 2

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int depth = 0;

        queue<TreeNode*> q;
        q.push(root);

        while(!(q.empty())) {
            depth++;
            int n = q.size();
            for(int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }

        return depth;
    }
};
