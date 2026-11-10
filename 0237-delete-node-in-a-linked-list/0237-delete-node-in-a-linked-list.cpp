/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* t = node->next;

        while(t != nullptr){
            swap(t->val , node->val);
            t = t->next;
            if(t != nullptr){
                node = node->next;
            }
        }

        node->next = nullptr;
    }
};