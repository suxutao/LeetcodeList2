#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        ll ans=0,n=prices.size();
        vector<ll>pre(n+1),sum(n+1);
        for (int i = 0; i < n; ++i) {
            pre[i+1]=pre[i]+prices[i]*strategy[i];
            sum[i+1]=sum[i]+prices[i];
        }
        ans=pre[n];
        for (int i = k; i <= n; ++i) {
            ans= max(ans,sum[i]-sum[i-k/2]+pre[n]-pre[i]+pre[i-k]);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}