#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 从当前字符向前比对，从右往左挨个寻找重复字符。
        // 寻找到start时停止，若无重复，则窗口扩大。
        // 当寻找到时，更新max。next start = p + 1
        int max = 0, start = 0;
        for (int i = 0; i < s.length(); i++) {
            // 逐字符
            for (int j = i - 1; j >= start; j--) {
                // 向前比对
                if (s[j] == s[i]) {
                    // j点重复
                    start = j + 1;
                    break;
                }
            }
            max = max > i - start + 1 ? max : i - start + 1;
        }
        return max;
    }
};
int main() {
    Solution s;
	std::cout << s.lengthOfLongestSubstring("pwwkew");
    return 0;
}