#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    long long maxTotal(vector<int>& nums, string s) {
        ll n=s.size();
        array<ll,2>dp{0,0};
        if (s[0]=='1'){
            dp[0]=nums[0];
        }
        for (int i = 2; i <= n; ++i) {
            if (s[i-1]=='0'){
                dp[0]=dp[1]=max(dp[0],dp[1]);
            }else{
                dp[0]=max(dp[0],dp[1])+nums[i-1];
                dp[1]=dp[1]+nums[i-2];
            }
        }
        return max(dp[0],dp[1]);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}