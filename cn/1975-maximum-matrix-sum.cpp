#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size(),cnt=0,mn=INT_MAX;
        ll ans=0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j]<0){
                    cnt++;
                }
                mn=min(mn,abs(matrix[i][j]));
                ans+=abs(matrix[i][j]);
            }
        }
        if (cnt&1){
            ans-=mn*2;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}