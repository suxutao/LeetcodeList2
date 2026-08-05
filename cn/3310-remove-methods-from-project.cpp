#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int>ans,in(n),v(n);
        vector<vector<int>>g(n);
        for (auto &i: invocations){
            g[i[0]].push_back(i[1]);
            in[i[1]]++;
        }
        v[k]=1;
        auto dfs=[&](this auto&&dfs,int u)->void{
            for (auto &i: g[u]){
                in[i]--;
                if (v[i])
                    continue;
                v[i]=1;
                dfs(i);
            }
        };
        dfs(k);
        for (int i = 0; i < n; ++i) {
            if (v[i]&&in[i]){
                for (int j = 0; j < n; ++j) {
                    ans.push_back(j);
                }
                return ans;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!v[i])
                ans.push_back(i);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}