#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int ans=0,m=grid.size(),n=grid[0].size();
        vector<vector<int>>v(m+1,vector<int>(n+1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                v[i][j]=v[i-1][j]+v[i][j-1]-v[i-1][j-1]+grid[i-1][j-1];
                if (v[i][j]<=8)
                    ++ans;
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}