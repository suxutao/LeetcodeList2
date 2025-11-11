#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int ns=strs.size();
        vector<array<int,2>>v(ns);
        vector<vector<int>>dp(m+1,vector<int>(n+1));
        for (int i = 0; i < ns; ++i) {
            v[i][0]=count(strs[i].begin(), strs[i].end(),'0');
            v[i][1]=strs[i].size()-v[i][0];
            if (v[i][0]<=m&&v[i][1]<=n){
                for (int j = m; j >= v[i][0]; --j) {
                    for (int k = n; k >= v[i][1]; --k) {
                        dp[j][k]=max(dp[j][k],1+dp[j-v[i][0]][k-v[i][1]]);
                    }
                }
            }
        }
        return dp[m][n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}