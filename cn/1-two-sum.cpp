#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>m;
        for (int i = 0; i < n; ++i) {
            if (m.contains(target-nums[i]))
                return {m[target-nums[i]],i};
            m[nums[i]]=i;
        }
        return {};
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    vector<int>v{1};
    Solution().twoSum(v,1);
    return 0;
}