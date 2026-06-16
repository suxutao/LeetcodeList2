#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int ans = 0;
        for (int i = max(0, n - k); i <= n + k; ++i) {
            if ((n & i) == 0)
                ans+=i;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}