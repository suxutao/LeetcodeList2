#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>m;
        ranges::sort(nums);
        for (int i = 0; i < n; ++i) {
            ++m[nums[i]];
        }
        for (int i = 1; i < n; ++i) {
            if (nums[i]!=nums[0]&&m[nums[i]]!=m[nums[0]]){
                return {nums[0],nums[i]};
            }
        }
        return {-1,-1};
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}