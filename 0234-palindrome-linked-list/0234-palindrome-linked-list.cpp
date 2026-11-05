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
    bool isPalindrome(ListNode* head) {
        ListNode* s = head;
        ListNode* f = head;
        ListNode* mid;

        if(head == nullptr || head->next == nullptr){
            return true;
        }

        while(f != nullptr){
            if(f->next == nullptr || f->next->next == nullptr){
                mid = s;
                break;
            }

            s = s->next;
            f = f->next->next;
        }

        ListNode* s1 = head;
        ListNode* s2 = mid->next;

        mid->next = nullptr;

        ListNode* rh = nullptr;
        ListNode* t = s2;

        while(s2 != nullptr){
            s2 = s2->next;
            t->next = rh;
            rh = t;
            t = s2;
        }

        s2 = rh;

        while(s2 != nullptr){
            if(s1->val != s2->val){
                return false;
            }

            s1 = s1->next;
            s2 = s2->next;
        }

        return true;
    }
};