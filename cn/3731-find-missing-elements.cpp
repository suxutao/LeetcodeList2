#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        ranges::sort(nums);
        for (int i = 1; i < n; ++i) {
            for (int j = nums[i-1]+1; j < nums[i]; ++j) {
                ans.push_back(j);
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}