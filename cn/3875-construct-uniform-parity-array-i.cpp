#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size(),ji=0,ou=0;
        if (n<=3)
            return true;
        for (int i = 0; i < n; ++i) {
            if (nums1[i]&1)
                ++ji;
            else
                ++ou;
        }
        return ji>=2||ou>=2;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}