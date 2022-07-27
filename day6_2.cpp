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
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return NULL;

        ListNode *ahead = head;
        ListNode *slow = head;
        while (n--)
        {
            ahead = ahead->next;
        }

        while (ahead != NULL && ahead->next != NULL)
        {
            slow = slow->next;
            ahead = ahead->next;
            cout << slow->val << " " << ahead->val << " "
                 << "\n";
        }
        if (slow == head && ahead == NULL)
        {
            head = head->next;
        }
        else
        {
            slow->next = slow->next->next;
        }
        return head;
    }
};