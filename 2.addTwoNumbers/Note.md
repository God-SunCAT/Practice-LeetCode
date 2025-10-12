| 名称       | 含义        | 定义方式         | 举例                             |
| -------- | --------- | ------------ | ------------------------------ |
| **数组指针** | 指针，指向一个数组 | `T (*p)[N];` | `int (*p)[5] = new int[3][5];` |
| **指针数组** | 数组，元素都是指针 | `T* p[N];`   | `int* p[3];`                   |

| 类型         | 定义                       | 分配方式                 | 释放方式                                  |
| ---------- | ------------------------ | -------------------- | ------------------------------------- |
| **数组指针**   | `int (*p)[5];`           | `p = new int[3][5];` | `delete[] p;`                         |
| **指针数组**   | `int* p[3];`             | `p[i] = new int[5];` | `for(...) delete[] p[i];`             |
| **动态指针数组** | `int** p = new int*[3];` | `p[i] = new int[5];` | `for(...) delete[] p[i]; delete[] p;` |

```
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
```

While方法要将next放在前面，不然不好处理。

```
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* cur = &dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = x + y + carry;

            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return dummy.next;
    }
};
```

```
int* p[N]; -> 指针的数组
int (*p)[N]; -> 数组的指针
```

在传递问题中务必好好考虑末项如何处理。

要好好想办法提高代码复用性。



while循环通常写法不会对最后条件项进行处理，但如果后面再加代码就太臃肿了。那么，直接让判断条件为本项。传递到本项不存在为止！
