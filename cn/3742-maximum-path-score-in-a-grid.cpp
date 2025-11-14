#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<vector<int>>>v(m,vector<vector<int>>(n,vector<int>(k+1,INT_MIN)));
        if (grid[0][0])
            v[0][0][1]=grid[0][0];
        else
            v[0][0][0]=0;
        for (int i = 1; i < m; ++i) {
            if (grid[i][0]==0)
                v[i][0][0]=v[i-1][0][0];
            for (int j = 1; j <= k; ++j) {
                if (grid[i][0]){
                    v[i][0][j]=v[i-1][0][j-1]+grid[i][0];
                }else{
                    v[i][0][j]=v[i-1][0][j];
                }
            }
        }
        for (int i = 1; i < n; ++i) {
            if (grid[0][i]==0)
                v[0][i][0]=v[0][i-1][0];
            for (int j = 1; j <= k; ++j) {
                if (grid[0][i]){
                    v[0][i][j]=v[0][i-1][j-1]+grid[0][i];
                }else{
                    v[0][i][j]=v[0][i-1][j];
                }
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (grid[i][j]==0)
                    v[i][j][0]=max(v[i-1][j][0],v[i][j-1][0]);
                for (int l = 1; l <= k; ++l) {
                    if (grid[i][j]){
                        v[i][j][l]=max(v[i-1][j][l-1],v[i][j-1][l-1])+grid[i][j];
                    }else{
                        v[i][j][l]=max(v[i-1][j][l],v[i][j-1][l]);
                    }
                }
            }
        }
        int mx=ranges::max(v[m-1][n-1]);
        return mx<0?-1:mx;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    vector<vector<int>>v{{0,1},{2,0}};
    Solution().maxPathScore(v,1);
    return 0;
}