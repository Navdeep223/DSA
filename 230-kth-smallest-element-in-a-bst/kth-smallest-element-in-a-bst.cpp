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
class Solution {
public:
int count=0;
    int kthSmallest(TreeNode* root, int k) {
        if (root == NULL)
            return -1;

        int left = kthSmallest(root->left, k);

        // If answer was found in left subtree
        if (left!=-1)
            return left;

        count++;

        // Current node is the kth smallest
        if (count==k)
            return root->val;

        return kthSmallest(root->right, k);
    }
};