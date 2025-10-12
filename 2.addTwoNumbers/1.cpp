// 没注意到条件，100位数字什么类型都无法处理

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
        // 首先将两数还原
        // 用循环的方式还原数字
        long long i = 1, i1 = 0, i2 = 0;
        ListNode* nextNode = l1;
        // 循环链必须选取判断点，这里选择next作为判断点
        while(nextNode -> next){
            i1 += (nextNode -> val) * i;
            nextNode = nextNode -> next;

            i *= 10;
        }
        i1 += (nextNode -> val) * i;
        // 上述循环不会处理最后nullptr

        i = 1;
        nextNode = l2;
        while(nextNode -> next){
            i2 += (nextNode -> val) * i;
            nextNode = nextNode -> next;

            i *= 10;
        }
        i2 += (nextNode -> val) * i;

        // 计算结果
        long long i3 = i1 + i2;

        // 构造返回值
        // 这里使用取余的值，传递值为除10取整。当取整值为0时，则取值完毕。
        int m = 0;
        ListNode *l3 = new ListNode(0, nullptr);
        nextNode = l3;
        while(i3 / 10 != 0){
            m = i3 % 10;
            nextNode -> val = m;
            nextNode -> next = new ListNode(0, nullptr);
            nextNode = nextNode -> next;
            
            i3 = i3 / 10;
        }
        // 上述循环没有处理最后一值
        nextNode -> val = i3 % 10;

        return l3;
    }
};