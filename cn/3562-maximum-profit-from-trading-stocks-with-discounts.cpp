#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ad = array<int, 2>;
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        vector<vector<int>>g(n);
        for (auto &i: hierarchy){
            g[i[0]-1].push_back(i[1]-1);
        }
        auto dfs=[&](this auto&&dfs,int u)->vector<ad>{
            vector<ad>suf(budget+1),f(budget+1);
            for (auto &i: g[u]){
                auto fi=dfs(i);
                for (int j = budget; j >= 0; --j) {
                    for (int jk = 0; jk <= j; ++jk) {
                        for (int k = 0; k < 2; ++k) {
                            suf[j][k]=max(suf[j][k],suf[j-jk][k]+fi[jk][k]);
                        }
                    }
                }
            }
            for (int j = 0; j <= budget; ++j) {
                for (int k = 0; k < 2; ++k) {
                    int cost=present[u]/(k+1);
                    if (cost>j){
                        f[j][k]=suf[j][0];
                    }else{
                        f[j][k]=max(suf[j][0],suf[j-cost][1]+future[u]-cost);
                    }
                }
            }
            return f;
        };
        return dfs(0)[budget][0];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}