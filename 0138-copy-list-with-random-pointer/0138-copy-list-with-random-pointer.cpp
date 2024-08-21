/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertattail(Node*& head, Node*& tail, int d) {
        Node* newNode = new Node(d);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node* copyRandomList(Node* head) {
        // clone list
        Node* clonehead = NULL;
        Node* clonetail = NULL;

        Node* temp = head;

        while (temp != NULL) {
            insertattail(clonehead, clonetail, temp->val);
            temp = temp->next;
        }
        // map
        unordered_map<Node*, Node*> oldtonew;
        Node* clone = clonehead;
        temp = head;

        while (temp != NULL) {
            oldtonew[temp] = clone;
            temp = temp->next;
            clone = clone->next;
        }
        temp = head;
        clone = clonehead;

        while (temp != NULL) {
            clone->random = oldtonew[temp->random];
            temp = temp->next;
            clone = clone->next;
        }

        return clonehead;
    }
};