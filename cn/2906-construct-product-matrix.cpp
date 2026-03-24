#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    const int N=12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        ll m=grid.size(),n=grid[0].size(),pre=1;
        vector<vector<int>>ans(m,vector<int>(n));
        vector<ll>suf(m*n+1);
        suf.back()=1;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                suf[i*n+j]=suf[i*n+j+1]*grid[i][j]%N;
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[i][j]=suf[i*n+j+1]*pre%N;
                pre=pre*grid[i][j]%N;
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}