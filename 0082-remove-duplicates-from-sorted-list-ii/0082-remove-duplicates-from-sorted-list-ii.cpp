class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // empty list
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* curr = head;
        // making prev node before head node to remove nodes in between
        ListNode* dummy = new ListNode(0, head);
        // making dummy because prev will move ahead but dummy with stay
        ListNode* prev = dummy;

        while (curr != NULL) {
            if (curr->next != NULL && curr->val == curr->next->val) {
                while (curr->next != NULL && curr->val == curr->next->val) {
                    curr = curr->next;
                }
                prev->next = curr->next;
            } else {
                prev = curr;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};