#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& good) {
        vector<int>m(n),dp(n);
        vector<vector<int>>g(n);
        for (auto &i: edges){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        for (int i = 0; i < n; ++i) {
            if (good[i]==0)
                good[i]=-1;
        }
        auto dfs=[&](this auto&&dfs,int u,int fa)->void{
            for (auto &i: g[u]){
                if (i==fa)
                    continue;
                dfs(i,u);
                if (m[i]>0)
                    m[u]+=m[i];
            }
            m[u]+=good[u];
        };
        auto dfs2=[&](this auto&&dfs2,int u,int fa)->void{
            for (auto &i: g[u]){
                if (i==fa)
                    continue;
                dp[i]=m[i]+max(0,dp[u]-max(0,m[i]));
                dfs2(i,u);
            }
        };
        dfs(0,0);
        dp[0]=m[0];
        dfs2(0,0);
        return dp;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}