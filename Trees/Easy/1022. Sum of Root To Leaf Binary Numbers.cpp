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

// dfs recursive Solution
// Time Complexity: O(n)
// Space Complexity: O(h)

class Solution {
public:
    int sumRootToLeaf(TreeNode* root, int currentValue = 0) {
        if(!(root)) return 0;
        currentValue *= 2;
        currentValue += root->val;
        if(!(root->left) && !(root->right))
            return currentValue;
        return sumRootToLeaf(root->left, currentValue) + sumRootToLeaf(root->right, currentValue);
    }
};

// dfs iterative Solution
// Time Complexity: O(n)
// Space Complexity: O(h)

class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        if(!root) return 0;

        stack<pair<TreeNode*, int> > st;
        st.push(make_pair(root, 0));

        int sum = 0;

        while(!(st.empty())) {
            TreeNode *currentNode = st.top().first;
            int currentValue = st.top().second << 1 | currentNode->val;
            st.pop();

            if(!(currentNode->left) && !(currentNode->right)) {
                sum += currentValue;
            }

            if(currentNode->left) st.push(make_pair(currentNode->left, currentValue));
            if(currentNode->right) st.push(make_pair(currentNode->right, currentValue));
        }

        return sum;
    }
};
