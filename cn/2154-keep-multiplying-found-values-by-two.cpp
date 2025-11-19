#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int>s(nums.begin(),nums.end());
        while (s.contains(original)){
            original<<=1;
        }
        return original;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}