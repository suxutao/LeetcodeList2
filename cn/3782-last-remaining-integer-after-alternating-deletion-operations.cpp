#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    long long lastInteger(long long n) {
        ll start=1,d=1;
        for (; n > 1; n=(n+1)/2) {
            start+=(n-2+n%2)*d;
            d*=-2;
        }
        return start;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}