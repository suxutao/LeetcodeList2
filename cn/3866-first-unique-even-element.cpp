#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>m;
        for (int i = 0; i < n; ++i) {
            ++m[nums[i]];
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i]%2==0&&m[nums[i]]==1)
                return nums[i];
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}