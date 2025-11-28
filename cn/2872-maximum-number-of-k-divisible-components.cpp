#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        int ans=0;
        vector<vector<int>>g(n);
        for (auto &i: edges){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        auto dfs=[&](this auto&&dfs,int u,int fa)->int{
            int sum=values[u]%k;
            for (auto &i: g[u]){
                if (i==fa)
                    continue;
                int t=dfs(i,u);
                if (t)
                    sum=(sum+t)%k;
            }
            if (sum==0)
                ++ans;
            return sum;
        };
        dfs(0,0);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}