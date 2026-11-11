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
    void reorderList(ListNode* head) {
        ListNode* t = head;

        if(head->next == nullptr){
            return;
        }

        while(t->next != nullptr && t->next->next != nullptr){
            ListNode* i = t;
            while(i->next->next != nullptr){
                i = i->next;
            }

            ListNode* last = i->next;
            i->next = nullptr;
            last->next = t->next;
            t->next = last;
            t = t->next->next;
        }
    }
};