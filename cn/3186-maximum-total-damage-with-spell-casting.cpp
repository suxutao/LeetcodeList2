#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;

    long long maximumTotalDamage(vector<int> &power) {
        ll n = power.size(), ans = 0;
        map<int, int> m;
        for (int i = 0; i < n; ++i) {
            ++m[power[i]];
        }
        vector<pair<int, int>> v;
        for (auto &item: m)
            v.push_back(item);
        n = v.size();
        vector<ll> dp(n + 1);
        for (int i = 0, j = 0; i < n; ++i) {
            while (v[j].first<v[i].first-2)
                ++j;
            dp[i+1]=max(dp[i],dp[j]+(ll)v[i].first*v[i].second);
        }
        return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}