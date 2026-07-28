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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        //Create a vector of linked list pointers
        vector<ListNode*> parts(k, nullptr);

        //Find length of linked list
        int len = 0;
        for (ListNode* node = root; node; node = node->next)
            len++;

        // Calculate minimum guaranteed part size (n) and number of extra nodes (r)
        int n = len / k;
        int r = len % k;

        // Initialize the pointers to traverse LL
        ListNode* node = root, *prev = nullptr;

        //Outer Loop
        for(int i = 0; node && i<k; i++, r--){
            
            //Store current node as start of current part
            parts[i] = node;

            //Traverse n+1 nodes if there are remianing extra nodes (r > 0)
            //Else traverse n nodes only
            for(int j = 0; j < n + (r > 0); j++){
                prev = node;
                node = node->next;
            }

            //Disconnect current part from rest of LL
            prev->next = nullptr;
        }

        //Return array of k parts
        return parts;
    }
};