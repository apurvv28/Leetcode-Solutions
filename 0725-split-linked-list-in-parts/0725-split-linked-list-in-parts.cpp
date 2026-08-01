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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> parts(k, nullptr);
        int len = 0;
        ListNode* temp = head;
        while(temp){
            temp=temp->next;
            len++;
        }
        int n = len/k;
        int r = len%k;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        for(int i = 0; i < k && curr; i++, r--){
            parts[i] = curr;
            for(int j = 0; j < n+(r>0); j++){
                prev = curr;
                curr = curr->next;
            }
            prev->next = nullptr;
        }
        return parts;
        
    }
};