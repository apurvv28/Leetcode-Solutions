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
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy1(0);
        ListNode dummy2(0);
        ListNode* l1 = &dummy1;
        ListNode* l2 = &dummy2;
        while(head){
            if(head->val<x){
                l1 = l1->next = head;
            }else{
                l2 = l2->next = head;
            }
            head = head->next;
        }
        l2->next = NULL;
        l1->next = dummy2.next;
        return dummy1.next;
    }
};