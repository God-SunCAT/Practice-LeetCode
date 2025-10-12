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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 应当充分考虑题目要求，如100位数字。
        // 该要求不适用于任何整型数据格式，则不可考虑 转换-计算-转换 方法。
        // 由于为倒序，可以考虑逐项相加进位。
        // 本次不考虑复用已有节点，全部开辟新内存空间。
        // 当遍历到某一链表的nullptr时，则对未遍历完数据进行复制(不开辟了内存空间了，取个巧吧)。
        // 进行逐节点相加
        int i, j, k;

        ListNode *next1 = new ListNode(), *next2 = new ListNode();
        ListNode *p = nullptr;
        ListNode *l3 = new ListNode(0, nullptr);
        ListNode *next3 = l3;

        next1 -> next = l1;
        next2 -> next = l2;
        while(next1 -> next && next2 -> next){
            next1 = next1 -> next;
            next2 = next2 -> next;

            i = next1 -> val + next2 -> val + next3 -> val;
            j = i % 10; // 本位
            k = i / 10; // 进位
            
            next3 -> val = j;
            next3 -> next = new ListNode(k, nullptr);
            
            p = next3;
            next3 = next3 -> next;
        }

        // 处理溢出节点
        // 这里有可能有连续进位产生！
        while(next1 -> next){
            next1 = next1 -> next;

            i = next1 -> val + next3 -> val;
            j = i % 10; // 本位
            k = i / 10; // 进位
            
            next3 -> val = j;
            next3 -> next = new ListNode(k, nullptr);

            p = next3;
            next3 = next3 -> next;
        }

        while(next2 -> next){
            next2 = next2 -> next;

            i = next2 -> val + next3 -> val;
            j = i % 10; // 本位
            k = i / 10; // 进位
            
            next3 -> val = j;
            next3 -> next = new ListNode(k, nullptr);

            p = next3;
            next3 = next3 -> next;
        }

        // 处理最后一位 避免出现最后为0的情况
        if(next3 -> val == 0){
            delete next3;
            p -> next = nullptr;
        }
        return l3;

    }
};