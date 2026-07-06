#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n=nums.size(),cnt=0;
        for (int i = 0; i < n; ++i) {
            if (nums[i]==nums[n/2])
                cnt++;
        }
        return cnt==1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}