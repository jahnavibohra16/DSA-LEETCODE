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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* temp = head;

        //Find the total length of the list
        while (temp != NULL) {
            length++;
            temp = temp->next;
        }

        //If deleting the head node
        if (n == length) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        //Move to the node just before the one to be deleted
        temp = head;
        for (int i = 1; i < length - n; i++) {
            temp = temp->next;
        }

        //Delete the nth node from end
        ListNode* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;

        return head;
    }
};
