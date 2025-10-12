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
        // 这次的目的是好，不是过！
        // 先处理共有位相加，再进行补充
        // 求模为本位，除10取整为下一位
        int sum = 0;
        ListNode *l3 = new ListNode();
        ListNode *p = l3;
        while(l1 || l2){
            int x = l1? l1 -> val: 0;
            int y = l2? l2 -> val: 0;

            if(l1) l1 = l1 -> next;
            if(l2) l2 = l2 -> next;

            sum = x + y + p -> val;
            p -> val = sum % 10;

            // 判断接下来是否还有节点，如果没有节点且没有进位则本项结束。
            if(!(l1 || l2) && (sum / 10) == 0){
                p -> next = nullptr;
            }else{
                p -> next = new ListNode(sum / 10);
            }
            p = p -> next;
        }
        return l3;
    }
};