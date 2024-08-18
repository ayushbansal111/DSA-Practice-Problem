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
    ListNode* solve(ListNode*& first, ListNode*& second) {
        ListNode* curr = first;
        ListNode* curr1 = second;
        ListNode* next = curr->next;
        ListNode* next1 = curr1->next;

        if (first->next == NULL) {
            first->next = second;
            return first;
        }

        while (curr1 != NULL && next != NULL) {
            if ((curr1->val >= curr->val) && (curr1->val <= next->val)) {
                curr->next = curr1;
                next1 = curr1->next;
                curr1->next = next;
                curr = curr1;
                curr1 = next1;
            } else {
                curr = next;
                next = next->next;

                if (next == NULL) {
                    curr->next = curr1;
                    return first;
                }
            }
        }
        return first;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        if (list1->val <= list2->val)
            return solve(list1, list2);
        else {
            return solve(list2, list1);
        }
    }
};