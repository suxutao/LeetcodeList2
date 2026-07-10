#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int mn=INT_MAX,ans=0;
        vector<int>dp(budget+1);
        for (auto &i: items){
            int cnt=0;
            mn=min(mn,i[1]);
            for (auto &j: items){
                if (j[0]%i[0]==0)
                    cnt++;
            }
            for (int j = budget; j >= i[1]; --j) {
                dp[j]=max(dp[j],dp[j-i[1]]+cnt);
            }
        }
        for (int i = 0; i <= budget; ++i) {
            ans=max(ans,dp[i]+(budget-i)/mn);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}