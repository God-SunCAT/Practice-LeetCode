#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // �ӵ�ǰ�ַ���ǰ�ȶԣ��������󰤸�Ѱ���ظ��ַ���
        // Ѱ�ҵ�startʱֹͣ�������ظ����򴰿�����
        // ��Ѱ�ҵ�ʱ������max��next start = p + 1
        int max = 0, start = 0;
        for (int i = 0; i < s.length(); i++) {
            // ���ַ�
            for (int j = i - 1; j >= start; j--) {
                // ��ǰ�ȶ�
                if (s[j] == s[i]) {
                    // j���ظ�
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