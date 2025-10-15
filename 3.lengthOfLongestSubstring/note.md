不要轻易用不了解的黑箱！！

for循环结束条件可以通过起始条件来分析，只要把其实条件换成结尾条件就好。



| 项目       | 哈希表 (`unordered_map`) | 红黑树 (`map`)                      |
| -------- | --------------------- | -------------------------------- |
| 底层结构     | 哈希表（数组 + 链表）          | 红黑树（平衡二叉搜索树）                     |
| 数据顺序     | 无序                    | 有序（按 key 排序）                     |
| 查找速度     | 平均 O(1)               | O(log n)                         |
| 插入删除     | 平均 O(1)               | O(log n)                         |
| 是否可排序    | ❌ 否                   | ✅ 可排序                            |
| 是否支持区间查找 | ❌ 否                   | ✅ 支持（如 lower_bound, upper_bound） |
| 内存消耗     | 较多                    | 较少                               |

```
#include <unordered_map>

// 定义
unordered_map<char, int> m;          // 空map
unordered_map<string, int> scores = {{"Tom", 90}, {"Bob", 85}};

// 插入元素
m['a'] = 1;              // 直接赋值（自动插入）
m.insert({'b', 2});      // 用 insert 插入
m.insert(make_pair('c', 3));



// 查找与访问
if (m.count('a')) {           // 判断是否存在
    cout << m['a'] << endl;   // 访问 value
}

auto it = m.find('b');        // 查找返回迭代器
if (it != m.end()) {
    cout << it->first << ":" << it->second;
}

// 遍历
for (auto& p : m) {
    cout << p.first << " -> " << p.second << endl;
}
```

对于需要连续遍历位置的程序，可以用数组记录最新位置