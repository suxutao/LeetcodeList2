#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    const int N=1e9+7;
    using ll = long long;
    int distinctSubseqII(string s) {
        int n=s.size();
        ll dp[26]{};
        for (int i = 0; i < n; ++i) {
            dp[s[i]-'a']=(1+ accumulate(dp, dp + 26, 0ll))%N;
        }
        return accumulate(dp,dp+26,0ll)%N;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}