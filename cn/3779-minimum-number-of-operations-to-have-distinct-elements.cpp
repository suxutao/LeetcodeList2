#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size(),pos=n;
        unordered_set<int>s;
        for (int i = n - 1; i >= 0; --i) {
            if (s.contains(nums[i])){
                pos=i;
                break;
            }
            s.insert(nums[i]);
        }
        if (pos==n)
            return 0;
        return pos/3+1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}