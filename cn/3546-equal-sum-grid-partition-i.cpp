#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    bool canPartitionGrid(vector<vector<int>>& grid) {
        ll m=grid.size(),n=grid[0].size(),sum=0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                sum+=grid[i][j];
            }
        }
        ll row=0,col=0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                row+=grid[i][j];
            }
            if (row*2==sum)
                return true;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                col+=grid[j][i];
            }
            if (col*2==sum)
                return true;
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}