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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;

        int num = t1->val + t2->val;
        ListNode* h = new ListNode(num%10);
        int carry = num/10;

        ListNode* t = h;

        while(t1->next != nullptr || t2->next != nullptr || carry != 0){
            if(t1->next == nullptr){
                t1->next = new ListNode(0);
            }

            if(t2->next == nullptr){
                t2->next = new ListNode(0);
            }

            t1 = t1->next;
            t2 = t2->next;

            int n = t1->val + t2->val + carry;

            ListNode* temp = new ListNode(n%10);
            carry = n / 10;

            t->next = temp;
            t = t->next;
        }
        t->next = nullptr;

        return h;
    }
};