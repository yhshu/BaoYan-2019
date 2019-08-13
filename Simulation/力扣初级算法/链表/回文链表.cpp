// 空间复杂度 O(1) 时间复杂度 O(n)
// 回文判断无法在不改变链表的情况下实现

// 快慢指针获得链表中点，然后反转后半段链表
// 判断前半段链表和后半段链表是否一致

// 注意：快慢指针的初始值都是 head

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode *head) {
        if (head == nullptr || head->next == nullptr) { // 0个或1个结点
            return true;
        }

        ListNode *slow = head;  // 注意快慢指针的初始值
        ListNode *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = reverseList(slow->next);
        slow = slow->next;

        while (slow) {
            if (head->val != slow->val)
                return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }

    ListNode *reverseList(ListNode *head) {
        if (head == nullptr) return head;

        ListNode *cur = head;
        ListNode *pre = nullptr;
        while (cur) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};