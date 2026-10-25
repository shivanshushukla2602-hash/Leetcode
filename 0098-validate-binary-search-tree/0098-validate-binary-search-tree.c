/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 struct TreeNode* p = NULL;
 bool isBST = true;

 void inOrder(struct TreeNode* root);

bool isValidBST(struct TreeNode* root) {
    p = NULL;
    isBST = true;

    inOrder(root);
    return isBST;
}

void inOrder(struct TreeNode* root){
    struct TreeNode* curr = root;

    if(root == NULL || !isBST){
        return;
    }

    inOrder(curr->left);
    if(p!=NULL && p->val >= curr->val){
        isBST = false;
        return;
    }
    p = curr;
    inOrder(curr->right);

}