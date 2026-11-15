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
    ListNode* reverseList(ListNode* head) {
        auto it = head;
        ListNode* prev = nullptr;
        while (it != nullptr) {
            auto next = it->next;
            it->next = prev;
            prev = it;
            it = next;
        }
        return prev;
    }
};
