#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m=mat.size(),n=mat[0].size();
        for (int i = 0; i < m; ++i) {
            if (i&1){
                for (int j = 0; j < n; ++j) {
                    if (mat[i][j]!=mat[i][((j-k)%n+n)%n])
                        return false;
                }
            }else{
                for (int j = 0; j < n; ++j) {
                    if (mat[i][j]!=mat[i][(j+k)%n])
                        return false;
                }
            }
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}