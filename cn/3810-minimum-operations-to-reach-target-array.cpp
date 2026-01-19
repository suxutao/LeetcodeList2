#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        int n=nums.size();
        unordered_set<int>s;
        for (int i = 0; i < n; ++i) {
            if (nums[i]!=target[i])
                s.insert(nums[i]);
        }
        return s.size();
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}