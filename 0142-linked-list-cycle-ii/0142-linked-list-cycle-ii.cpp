class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                while (slow != temp) {
                    slow = slow->next;
                    temp = temp->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};