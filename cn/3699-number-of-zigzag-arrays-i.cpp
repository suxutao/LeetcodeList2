#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    const int N=1e9+7;
    using ll = long long;
    int zigZagArrays(int n, int l, int r) {
        r-=l;
        vector<array<ll,2>>dp(r+1);
        vector<ll>suf(r+2),pre(r+2);
        dp[0][0]=dp[0][1]=1;
        dp[r][0]=dp[r][1]=1;
        for (int i = 1; i <= n; ++i) {
            for (int j = r; j >= 0; --j) {
                suf[j]=(suf[j+1]+dp[j][1])%N;
            }
            for (int j = 0; j <= r; ++j) {
                pre[j+1]=(pre[j]+dp[j][0])%N;
            }
            for (int j = 0; j <= r; ++j) {
                dp[j][0]=suf[j+1];
                dp[j][1]=pre[j];
            }
        }
        ll ans=0;
        for (int i = 0; i <= r; ++i) {
            ans=(ans+dp[i][0]+dp[i][1])%N;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}