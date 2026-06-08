#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int>ans;
        for (int i = 0; i < n; ++i) {
            if (nums[i]<pivot)
                ans.push_back(nums[i]);
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i]==pivot)
                ans.push_back(nums[i]);
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i]>pivot)
                ans.push_back(nums[i]);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}