#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int ans=1,m=grid.size(),n=grid[0].size();
        auto check=[&](int x,int y,int sq)->bool {
            int sum=0,sum2=0;
            for (int i = 0; i < sq; ++i) {
                sum+=grid[x+i][y+i];
                sum2+=grid[x+i][y+sq-i-1];
            }
            if (sum!=sum2)
                return false;
            for (int i = 0; i < sq; ++i) {
                int row=0,col=0;
                for (int j = 0; j < sq; ++j) {
                    row+=grid[x+i][y+j];
                    col+=grid[x+j][y+i];
                }
                if (row!=sum||col!=sum)
                    return false;
            }
            return true;
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int sq = 2; sq <= min(m - i, n - j); ++sq) {
                    if (sq>ans&&check(i,j,sq)){
                        ans=sq;
                    }
                }
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}