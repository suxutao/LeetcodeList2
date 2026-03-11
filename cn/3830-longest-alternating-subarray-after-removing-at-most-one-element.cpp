#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    vector<int> calc(const vector<int>& a) {
        int n = a.size();
        vector<int> f(n); // f[i] 表示以 i 结尾的最长交替子数组的长度
        for (int i = 0; i < n; i++) {
            if (i == 0 || a[i - 1] == a[i]) {
                f[i] = 1;
            } else if (i > 1 && a[i - 2] != a[i - 1] && (a[i - 2] < a[i - 1]) == (a[i - 1] > a[i])) {
                f[i] = f[i - 1] + 1;
            } else {
                f[i] = 2;
            }
        }
        return f;
    }

public:
    int longestAlternating(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre = calc(nums); // pre[i] 表示以 i 结尾的最长交替子数组的长度

        ranges::reverse(nums);
        vector<int> suf = calc(nums); // suf[i] 表示以 i 开头的最长交替子数组的长度
        ranges::reverse(suf);
        ranges::reverse(nums);

        // 不删除元素时的最长交替子数组的长度
        int ans = ranges::max(pre);

        // 枚举删除 nums[i]
        for (int i = 1; i < n - 1; i++) {
            if (nums[i - 1] == nums[i + 1]) { // 无法拼接
                continue;
            }

            // 计算 (i-2,i-1), (i-1,i+1), (i+1,i+2) 的大小关系
            int x = i > 1 ? (nums[i - 2] > nums[i - 1]) - (nums[i - 2] < nums[i - 1]) : 0;
            int y = (nums[i - 1] > nums[i + 1]) - (nums[i - 1] < nums[i + 1]);
            int z = i < n - 2 ? (nums[i + 1] > nums[i + 2]) - (nums[i + 1] < nums[i + 2]) : 0;

            if (x == -y && x == z) { // 左右两边可以拼接
                ans = max(ans, pre[i - 1] + suf[i + 1]);
            } else {
                if (x == -y) {
                    ans = max(ans, pre[i - 1] + 1); // 只拼接 nums[i+1]
                }
                if (z == -y) {
                    ans = max(ans, suf[i + 1] + 1); // 只拼接 nums[i-1]
                }
            }
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}