#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size(),ans=0;
        vector<int>h(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j]==1){
                    h[j]++;
                }else{
                    h[j]=0;
                }
            }
            vector<int>g(h);
            ranges::sort(g);
            for (int j = 0; j < n; ++j) {
                ans=max(ans,g[j]*(n-j));
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}