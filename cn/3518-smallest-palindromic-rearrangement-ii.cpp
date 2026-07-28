#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string smallestPalindrome(string s, int k) {
        int n = s.size();
        int m = n / 2;

        int cnt[26]{};
        for (int i = 0; i < m; i++) {
            cnt[s[i] - 'a']++;
        }

        // 为什么这样做是对的？见 62. 不同路径 我的题解
        auto comb = [&](int n, int m) -> int {
            m = min(m, n - m);
            long long res = 1;
            for (int i = 1; i <= m; i++) {
                res = res * (n + 1 - i) / i;
                if (res >= k) { // 太大了
                    return k;
                }
            }
            return res;
        };

        // 计算长度为 sz 的字符串的排列个数
        auto perm = [&](int sz) -> int {
            long long res = 1;
            for (int c : cnt) {
                if (c == 0) {
                    continue;
                }
                // 先从 sz 个里面选 c 个位置填当前字母
                res *= comb(sz, c);
                if (res >= k) { // 太大了
                    return k;
                }
                // 从剩余位置中选位置填下一个字母
                sz -= c;
            }
            return res;
        };

        // k 太大
        if (perm(m) < k) {
            return "";
        }

        // 构造回文串的左半部分
        string left_s(m, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < 26; j++) {
                if (cnt[j] == 0) {
                    continue;
                }
                cnt[j]--; // 假设填字母 j，看是否有足够的排列
                int p = perm(m - i - 1); // 剩余位置的排列个数
                if (p >= k) { // 有足够的排列
                    left_s[i] = 'a' + j;
                    break;
                }
                k -= p; // k 太大，要填更大的字母（类似搜索树剪掉了一个大小为 p 的子树）
                cnt[j]++;
            }
        }

        string ans = left_s;
        if (n % 2) {
            ans += s[n / 2];
        }
        ranges::reverse(left_s);
        return ans + left_s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}