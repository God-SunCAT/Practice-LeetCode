struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// 对于while循环 存储节点要在循环创建时，如果使用堆就需要考虑释放
// 那么可以试着考虑扶持一个傀儡政权，出函数栈自带释放。
class Solution {
public:
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
        // 这次的目的是好，不是过！
        // 先处理共有位相加，再进行补充
        // 求模为本位，除10取整为下一位
        int sum = 0, carry = 0;
        ListNode dummy;
        ListNode *p = &dummy;
        while(l1 || l2 || carry){
            int x = l1? l1 -> val: 0;
            int y = l2? l2 -> val: 0;

            if(l1) l1 = l1 -> next;
            if(l2) l2 = l2 -> next;

            sum = x + y + carry;
            carry = sum / 10;

            p -> next = new ListNode(sum % 10);
            p = p -> next;
        }
        return dummy.next;
    }
};