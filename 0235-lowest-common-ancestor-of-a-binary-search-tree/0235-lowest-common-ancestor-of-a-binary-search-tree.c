/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode* curr = root;

    if(root == NULL){
        return NULL;
    }

    while(curr != NULL){
        if(curr->val > p->val && curr->val > q->val){
        curr = curr->left;
    }
    else if(curr->val < p->val && curr->val < q->val){
        curr = curr->right;
    }
    else{
        return curr;
    }
    }

    return NULL;
}