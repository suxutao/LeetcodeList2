#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    long long minTime(vector<int>& skill, vector<int>& mana) {
        ll n=skill.size(),m=mana.size();
        vector<ll>dp(n+1);
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[j]=max(dp[j-1],dp[j])+skill[j-1]*mana[i-1];
            }
            for (int j = n - 1; j >= 0; --j) {
                dp[j]=dp[j+1]-skill[j]*mana[i-1];
            }
        }
        return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}