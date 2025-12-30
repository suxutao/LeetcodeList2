#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),ans=0;
        auto check=[&](int x,int y)->bool{
            int row[3]{},col[3]{};
            unordered_set<int>s;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (grid[i+x][j+y]>9||grid[i+x][j+y]==0)
                        return false;
                    s.insert(grid[i+x][j+y]);
                    row[i]+=grid[i+x][j+y];
                    col[j]+=grid[i+x][j+y];
                }
            }
            if (s.size()<9)
                return false;
            int ans=row[0];
            for (int i = 0; i < 3; ++i) {
                if (ans!=row[i]||ans!=col[i])
                    return false;
            }
            return ans==grid[x][y]+grid[x+1][y+1]+grid[x+2][y+2]&&ans==grid[x+2][y]+grid[x+1][y+1]+grid[x][y+2];
        };
        for (int i = 0; i < m - 2; ++i) {
            for (int j = 0; j < n - 2; ++j) {
                if (check(i,j))
                    ans++;
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}