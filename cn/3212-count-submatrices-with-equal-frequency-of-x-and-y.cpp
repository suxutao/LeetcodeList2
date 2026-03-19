#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size(),ans=0;
        vector<vector<int>>x(m+1,vector<int>(n+1));
        vector<vector<int>>y(m+1,vector<int>(n+1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                x[i][j]=x[i-1][j]+x[i][j-1]-x[i-1][j-1]+(grid[i-1][j-1]=='X');
                y[i][j]=y[i-1][j]+y[i][j-1]-y[i-1][j-1]+(grid[i-1][j-1]=='Y');
                if (x[i][j]&&x[i][j]==y[i][j])
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