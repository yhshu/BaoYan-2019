// 给定的结点是非末尾结点，则可能是开始结点或中间结点
// 本题是单链表，头结点存储数据
// 所要求实现的函数只给定了一个参数，该参数就是要求删除的结点

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
    void deleteNode(ListNode *node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};