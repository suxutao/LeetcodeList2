#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>ans(m-k+1,vector<int>(n-k+1,INT_MAX));
        for (int i = 0; i <= m - k; ++i) {
            for (int j = 0; j <= n - k; ++j) {
                vector<int>v;
                for (int l = 0; l < k; ++l) {
                    for (int i1 = 0; i1 < k; ++i1) {
                        v.push_back(grid[i+l][j+i1]);
                    }
                }
                ranges::sort(v);
                for (int l = 1; l < v.size(); ++l) {
                    if (v[l]!=v[l-1])
                        ans[i][j]=min(ans[i][j],v[l]-v[l-1]);
                }
                if (ans[i][j]==INT_MAX)
                    ans[i][j]=0;
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}