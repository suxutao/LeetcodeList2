#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>>g(n);
        for (auto &i: edges){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        auto dfs=[&](this auto&&dfs,int u,int fa)->ll{
            ll mn=LLONG_MAX,mx=0;
            for (auto &i: g[u]){
                if (i==fa)
                    continue;
                ll time=dfs(i,u);
                mn=min(mn,time);
                mx=max(mx,time);
            }
            return mx==0?baseTime[u]:baseTime[u]+mx*2-mn;
        };
        return dfs(0,0);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}