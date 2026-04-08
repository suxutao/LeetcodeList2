#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        ll ans=0,N=1e9+7,n=nums.size();
        for (auto &q: queries){
            for (int i = q[0]; i <= q[1]; i+=q[2]) {
                nums[i]=(ll)nums[i]*q[3]%N;
            }
        }
        for (int i = 0; i < n; ++i) {
            ans^=nums[i];
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}