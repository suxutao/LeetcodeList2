#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n=nums.size(),ans=0;
        for (int i = 0; i < n; ++i) {
            int x=0,y=0;
            for (int j = i; j < n; ++j) {
                nums[j]&1?y++:x++;
                ans+=b*x<=a*y;
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}