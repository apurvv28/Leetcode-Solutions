/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
    Node* curr = head;
    while(curr){
        if(curr->child!=nullptr){
            Node* nextNode = curr->next;
            Node* childNode = curr->child;
            curr->next = childNode;
            childNode->prev = curr;
            curr->child = nullptr;

            Node* temp = childNode;
            while(temp->next){
                temp = temp->next;
            }
            if(nextNode){
                temp->next = nextNode;
            }
            if(nextNode){
                nextNode->prev = temp;
            }
        }
        curr = curr->next;
    }
    return head;
    }
};