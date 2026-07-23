#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if (n<=3)
            return 1<<(n-1);
        else
            return 1<<bit_width((unsigned)n);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}