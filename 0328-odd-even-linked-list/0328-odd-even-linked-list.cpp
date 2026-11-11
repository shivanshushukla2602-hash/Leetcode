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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* t = head;
        ListNode* rh = nullptr;

        if(head == nullptr){
            return nullptr;
        }

        if(head->next == nullptr || head->next->next == nullptr){
            return head;
        }

        while(t->next != nullptr){
            ListNode* temp = t->next;
            t->next = t->next->next;
            temp->next = rh;
            rh = temp;
            if(t->next != nullptr){
                t = t->next;
            }
        }

        ListNode* nrh = nullptr;
        while(rh != nullptr){
            ListNode* temp = rh;
            rh = rh->next;
            temp->next = nrh;
            nrh = temp; 
        }

        t->next = nrh;

        return head;
    }
};