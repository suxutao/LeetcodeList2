#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m=grid.size(),n=grid[0].size(),ans=INT_MAX,pre=0;
        vector<int>v;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                v.push_back(grid[i][j]);
            }
        }
        n=v.size();
        ranges::sort(v);
        for (int i = 1; i < n; ++i) {
            if ((v[i]-v[i-1])%x!=0){
                return -1;
            }
        }
        vector<int>sum(n+1);
        for (int i = n - 1; i >= 0; --i) {
            sum[i]=sum[i+1]+v[i];
        }
        for (int i = 0; i < n; ++i) {
            pre+=v[i];
            ans=min(ans,(v[i]*(i+1)-pre)/x+(sum[i+1]-v[i]*(n-i-1))/x);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}