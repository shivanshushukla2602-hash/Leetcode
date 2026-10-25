/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    struct TreeNode* curr = root;

    while(curr != NULL){
        if(curr->val < val){
        curr = curr->right;
    }
    else if(curr->val > val){
        curr = curr->left;
    }
    else{
        return curr;
    }

    }

    return NULL;


}