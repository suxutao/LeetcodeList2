#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size(),ans=0;
        for (int x = 1-n; x <= n-1; ++x) {
            for (int y = 1-n; y <= n-1; ++y) {
                int sum=0;
                for (int i = max(0,-x); i <= min(n-1,n-1-x); ++i) {
                    for (int j = max(0,-y); j <= min(n-1,n-1-y); ++j) {
                        sum+=img1[i+x][j+y]&img2[i][j];
                    }
                }
                ans=max(ans,sum);
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}