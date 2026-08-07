#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;

    long long minInitialStrength(vector<int> &monsters, vector<vector<int>> &boosts) {
        int n = monsters.size();
        ll ans = 0;
        vector<ll> cha(n + 1), add(n + 1);
        for (auto &i: boosts) {
            cha[i[0]] += i[2];
            cha[i[1] + 1] -= i[2];
        }
        for (int i = 0; i < n; ++i) {
            add[i + 1] = cha[i] + add[i];
        }
        for (int i = n - 1; i >= 0; --i) {
            if (ans == 0) {
                ans = max(0ll, monsters[i] - add[i + 1]);
            } else {
                ans += monsters[i];
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}