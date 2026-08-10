#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> memo(n + 1, -1), v;
        for (int i = 1; i * i <= n; ++i) {
            memo[i * i] = 1;
            v.push_back(i * i);
        }
        auto dfs = [&](this auto &&dfs, int x) -> bool {
            auto &val = memo[x];
            if (memo[x] == -1) {
                for (int i = 0; i < v.size() && x >= v[i]; ++i) {
                    if (dfs(x - v[i]) == 0) {
                        return memo[x] = 1;
                    }
                }
                memo[x] = 0;
            }
            return memo[x];
        };
        return dfs(n);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}