#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size(),ans=0;
        vector<int>v(n);
        for (int i = 0; i < n; ++i) {
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j])
                    break;
                v[i]++;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (v[i]<n-i-1){
                int pos=-1;
                for (int j = i+1; j < n; ++j) {
                    if (v[j]>=n-i-1){
                        pos=j;
                        break;
                    }
                }
                if (pos==-1)
                    return -1;
                for (int j = pos; j > i; --j) {
                    swap(v[j],v[j-1]);
                    ++ans;
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