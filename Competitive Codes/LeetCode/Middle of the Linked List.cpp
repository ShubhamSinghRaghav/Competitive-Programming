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
    ListNode* middleNode(ListNode* head){
       // if(head == NULL or head->next == NULL) return head;
        ListNode* save = head;
        ListNode* fast = head;
        while(fast!=NULL and fast->next!=NULL){
            save = save->next;
            fast = fast->next->next;
        }
        return save;
    }
};