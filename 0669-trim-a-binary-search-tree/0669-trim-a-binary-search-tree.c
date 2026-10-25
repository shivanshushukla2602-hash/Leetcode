/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* trimBST(struct TreeNode* root, int low, int high) {
    if(root == NULL){
        return NULL;
    }

    root->left = trimBST(root->left , low , high);
    root->right = trimBST(root->right , low , high);

    if(root->val >= low && root->val <= high){
        return root;
    }
    else{
        if(root->val < low){
            return root->right;
        }
        else{
            return root->left;
        }
    }
}