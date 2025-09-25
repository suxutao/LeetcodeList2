#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int>dp(n,INT_MAX/2);
        dp[0]=triangle[0][0];
        for (int i = 1; i < n; ++i) {
            for (int j = i; j; --j) {
                dp[j]=min(dp[j-1],dp[j])+triangle[i][j];
            }
            dp[0]+=triangle[i][0];
        }
        return ranges::min(dp);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}