#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n);
        for (int i = 0; i < n; ++i) {
            res[i]=nums[((i+nums[i])%n+n)%n];
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}