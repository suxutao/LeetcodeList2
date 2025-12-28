#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),p=0,ans=0;
        for (int i = m - 1; i >= 0; --i) {
            while (p<n&&grid[i][p]>=0)
                ++p;
            if (p==n)
                break;
            ans+=n-p;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}