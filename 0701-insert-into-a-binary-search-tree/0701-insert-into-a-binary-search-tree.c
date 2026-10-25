/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    struct TreeNode* curr = root;
    struct TreeNode* p = NULL;

    struct TreeNode* n = malloc(sizeof(struct TreeNode));
    n->val = val;
    n->left = NULL;
    n->right = NULL;

    if(root == NULL){
        return n;
    }

    while(curr != NULL){
        p = curr;

        if(curr->val > val){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }

    if(p->val > val){
        p->left = n;
    }
    else{
        p->right = n;
    }

    return root;
}