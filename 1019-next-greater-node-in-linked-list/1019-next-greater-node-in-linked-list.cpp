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
    ListNode* reverseList(ListNode* head){
        ListNode* rh = nullptr;
        ListNode* t = head;

        while(head != nullptr){
            head = head->next;
            t->next = rh;
            rh = t;
            t = head;
        }

        return rh;
    }

    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> v;
        stack<int> st;

        head = reverseList(head);
        ListNode* t = head;

        while(t != nullptr){
            while(st.size() > 0 && st.top() <= t->val){
                st.pop();
            }

            if(st.size() > 0){
                v.push_back(st.top());
            }
            else{
                v.push_back(0);
            }

            st.push(t->val);

            t = t->next;
        }

        reverse(v.begin() , v.end());

        return v;
    }
};