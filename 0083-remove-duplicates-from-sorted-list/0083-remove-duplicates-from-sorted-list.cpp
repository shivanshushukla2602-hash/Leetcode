/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* t = head;

        if(head == nullptr){
            return nullptr;
        }

        while(t != nullptr){
            if(t->next != nullptr && t->val == t->next->val){
                t->next = t->next->next;
            }
            else if(t->next == nullptr){
                break;
            }

            if(t->next != nullptr && t->val != t->next->val){
                t = t->next;
            }
            else if(t->next == nullptr){
                t = t->next;
            }
        }

        return head;
    }
};