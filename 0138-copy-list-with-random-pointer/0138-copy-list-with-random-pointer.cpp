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
        // add clone list nodes in between original list nodes
        Node* original = head;
        Node* clone = clonehead;

        while (original != NULL && clone != NULL) {
            Node* next = original->next;
            original->next = clone;
            original = next;

            next = clone->next;
            clone->next = original;
            clone = next;
        }
        // random pointer copy
        temp = head;
        while (temp != NULL) {
            if (temp->next != NULL) {
                temp->next->random =
                    temp->random ? temp->random->next : temp->random;
            }
            temp = temp->next->next;
        }
        // revert changes
        original = head;
        clone = clonehead;

        while (original != NULL && clone != NULL) {
            original->next = clone->next;
            original = original->next;

            if (original != NULL) {
                clone->next = original->next;
            }
            clone = clone->next;
        }

        return clonehead;
    }
};