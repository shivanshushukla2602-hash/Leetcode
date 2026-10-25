/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(root == NULL){
        return NULL;
    }
    if(root->val == p->val || root->val == q->val){
        return root;
    }

    struct TreeNode* l = lowestCommonAncestor(root->left , p , q);
    struct TreeNode* r = lowestCommonAncestor(root->right , p , q);

    if(l == NULL && r == NULL){
        return NULL;
    }
    else if(l == NULL){
        return r;
    }
    else if(r == NULL){
        return l;
    }
    else{
        return root;
    }
}