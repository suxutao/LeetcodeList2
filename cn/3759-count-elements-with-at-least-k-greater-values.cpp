#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n=nums.size(),ans=0,sum=0;
        map<int,int>m;
        for (int i = 0; i < n; ++i) {
            ++m[nums[i]];
        }
        for (auto &[a,b]: m){
            sum+=b;
            if (sum<=n-k){
                ans=sum;
            }else{
                break;
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}