#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 是否为奇数 odd
        int k = nums1.size() + nums2.size();
        bool oe = k % 2 ? true : false;

        // 计算前余量
        int v = oe ? k / 2 : k / 2 - 1;

        // 指针
        int p1 = 0, p2 = 0; // 跳过N个

        while (v != 0) {
            i1 = p1 + (v / 2 - 1 > 0 ? v / 2 - 1 : 0);
            i1 = i1 > (int)nums1.size() - 1 ? nums1.size() - 1 : i1;
            i1 = i1 < 0 ? 0 : i1;

            i2 = p2 + (v / 2 - 1 > 0 ? v / 2 - 1 : 0);
            i2 = i2 > (int)nums2.size() - 1 ? nums2.size() - 1 : i2;
            // 注：有符号数与无符号数一并运算会将无符号转换为有符号
            i2 = i2 < 0 ? 0 : i2;

            if (p1 == nums1.size()) {
                return oe ? nums2[p2 + v] : (nums2[p2 + v + 1] + nums2[p2 + v]) / 2.0;
            }
            if (p2 == nums2.size()) {
                return oe ? nums1[p1 + v] : (nums1[p1 + v + 1] + nums1[p1 + v]) / 2.0;
            }

            if (nums1[i1] > nums2[i2]) {
                v -= i2 + 1 - p2;
                p2 = i2 + 1;
            }
            if (nums1[i1] < nums2[i2]) {
                v -= i1 + 1 - p1;
                p1 = i1 + 1;
            }
            if (nums1[i1] == nums2[i2]) {
                v -= (i1 + 1 - p1) + (i2 + 1 - p2 - 1);
                p1 = i1 + 1;
                p2 = i2 + 1 - 1;
            }
        }
        if (oe) {
            // 奇数个
            if (p1 == nums1.size()) {
                return nums2[p2];
            }
            if (p2 == nums2.size()) {
                return nums1[p1];
            }
            return nums1[p1] > nums2[p2] ? nums2[p2] : nums1[p1];
        }
        // 偶数个
        if (p1 == nums1.size()) {
            return (nums2[p2] + nums2[p2 + 1]) / 2.0;
        }
        if (p2 == nums2.size()) {
            return (nums1[p1] + nums1[p1 + 1]) / 2.0;
        }
        int z[4];
        z[0] = nums1[p1];
        z[1] = p1 + 1 > nums1.size() - 1 ? 0 : nums1[p1 + 1];
        z[2] = nums2[p2];
        z[3] = p2 + 1 > nums2.size() - 1 ? 0 : nums2[p2 + 1];

        if (z[2] >= z[1] && z[1] != 0) {
            return (z[0] + z[1]) / 2.0;
        }
        if (z[0] >= z[3] && z[3] != 0) {
            return (z[2] + z[3]) / 2.0;
        }
        return (z[0] + z[2]) / 2.0;
    }
};
int main() {
    Solution s;
    vector<int> nums1 = {2,2,4,4};
    vector<int> nums2 = {2,2,4,4};

    std::cout << s.findMedianSortedArrays(nums1, nums2);
    return 0;
}