/**
 * Definition for singly-linked list->
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next){
            return true;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast&&fast->next&&fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *p = slow->next;
        ListNode *last = NULL;      //必须初始化赋值
        while(p){
            ListNode *t = p->next;
            p->next = last;
            last = p;
            p = t;
        }

        while(last && last->val==head->val){
            last = last->next;
            head = head->next;
        }

        if(!last){
            return true;
        }else{
            return false;
        }

    }
};