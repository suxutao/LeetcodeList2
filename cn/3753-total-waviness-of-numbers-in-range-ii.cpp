#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    long long totalWaviness(long long num1, long long num2) {
        string low_s = to_string(num1);
        string high_s = to_string(num2);
        int n = high_s.size();
        int diff_lh = n - low_s.size();
        vector memo(n, vector<array<array<long long, 10>, 3>>(n));

        auto dfs = [&](this auto&& dfs, int i, int waviness, int last_cmp, int last_digit, bool limit_low, bool limit_high) -> long long {
            if (i == n) {
                return waviness;
            }
            long long& ref = memo[i][waviness][last_cmp + 1][last_digit];
            if (!limit_low && !limit_high && ref) {
                return ref - 1;
            }

            int lo = limit_low && i >= diff_lh ? low_s[i - diff_lh] - '0' : 0;
            int hi = limit_high ? high_s[i] - '0' : 9;

            long long res = 0;
            bool is_num = !limit_low || i > diff_lh; // 前面是否填过数字
            for (int d = lo; d <= hi; d++) {
                // 当前填的数不是最高位，cmp 才有意义
                int cmp = is_num ? (d > last_digit) - (d < last_digit) : 0;
                int w = waviness + (cmp * last_cmp < 0);
                res += dfs(i + 1, w, cmp, d, limit_low && d == lo, limit_high && d == hi);
            }

            if (!limit_low && !limit_high) {
                ref = res + 1;
            }
            return res;
        };

        return dfs(0, 0, 0, 0, true, true);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}