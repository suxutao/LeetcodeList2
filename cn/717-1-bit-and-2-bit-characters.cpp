#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n=bits.size();
        for (int i = 0; i < n; ++i) {
            if (i==n-1&&bits[i]==0)
                return true;
            if (bits[i]==1)
                ++i;
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}