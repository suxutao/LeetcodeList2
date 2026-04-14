#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        ll nr=robot.size(),nf=factory.size();
        vector<vector<ll>>dp(nr+1,vector<ll>(nf+1,LLONG_MAX/2));
        ranges::sort(robot);
        ranges::sort(factory);
        for (int i = 0; i <= nf; ++i) {
            dp[0][i]=0;
        }
        for (int i = 1; i <= nr; ++i) {
            for (int j = 1; j <= nf; ++j) {
                ll sum=0;
                dp[i][j]=dp[i][j-1];
                for (int k = 1; k <= min(factory[j-1][1], i); ++k) {
                    sum+=abs((ll)factory[j-1][0]-robot[i-k]);
                    dp[i][j]=min(dp[i][j],sum+dp[i-k][j-1]);
                }
            }
        }
        return dp[nr][nf];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}