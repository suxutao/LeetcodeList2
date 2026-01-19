#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m=mat.size(),n=mat[0].size(),ans=0;
        vector<vector<int>>pre(m+1,vector<int>(n+1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                pre[i+1][j+1]=mat[i][j]+pre[i][j+1]+pre[i+1][j]-pre[i][j];
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 1; k <= min(m - i, n - j); ++k) {
                    int sum=pre[i+k][j+k]-pre[i][j+k]-pre[i+k][j]+pre[i][j];
                    if (sum<=threshold)
                        ans=max(ans,k);
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