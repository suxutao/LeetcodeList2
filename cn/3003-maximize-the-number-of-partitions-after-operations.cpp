#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;

    int maxPartitionsAfterOperations(string s, int k) {
        int n = s.size();
        unordered_map<ll, int> memo;
        auto dfs = [&](this auto &&dfs, int p, unsigned mask, bool changed) -> int {
            if (p == n)
                return 1;
            int bit = 1 << (s[p] - 'a'), ans = 0;
            unsigned new_mask = mask | bit;
            ll key = (ll) p << 32 | mask << 1 | changed;
            if (memo.contains(key))
                return memo[key];
            if (popcount(new_mask) > k) {
                ans = max(ans, 1 + dfs(p + 1, bit, changed));
            } else {
                ans = max(ans, dfs(p + 1, new_mask, changed));
            }
            if (!changed) {
                for (int i = 0; i < 26; ++i) {
                    new_mask = mask | (1 << i);
                    if (popcount(new_mask) > k)
                        ans = max(ans, 1 + dfs(p + 1, 1<<i, true));
                    else
                        ans = max(ans, dfs(p + 1, new_mask, true));
                }
            }
            return memo[key] = ans;
        };
        return dfs(0, 0, false);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}