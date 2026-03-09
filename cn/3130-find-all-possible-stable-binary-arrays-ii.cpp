#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1'000'000'007;
        vector memo(zero + 1, vector<array<int, 2>>(one + 1, {-1, -1})); // -1 表示没有计算过

        auto dfs = [&](this auto&& dfs, int i, int j, int k) -> int {
            if (i == 0) { // 递归边界
                return k == 1 && j <= limit;
            }
            if (j == 0) { // 递归边界
                return k == 0 && i <= limit;
            }
            int& res = memo[i][j][k]; // 注意这里是引用
            if (res != -1) { // 之前计算过
                return res;
            }
            if (k == 0) {
                // + MOD 保证答案非负
                res = ((long long) dfs(i - 1, j, 0) + dfs(i - 1, j, 1) +
                       (i > limit ? MOD - dfs(i - limit - 1, j, 1) : 0)) % MOD;
            } else {
                res = ((long long) dfs(i, j - 1, 0) + dfs(i, j - 1, 1) +
                       (j > limit ? MOD - dfs(i, j - limit - 1, 0) : 0)) % MOD;
            }
            return res;
        };

        return (dfs(zero, one, 0) + dfs(zero, one, 1)) % MOD;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}