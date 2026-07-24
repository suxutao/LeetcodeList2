#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    long long maximumValue(int n, int s, int m) {
        if (n==1)
            return s;
        ll ans=s;
        if (n&1)
            n--;
        ans+=(ll)(m-1)*n/2+1;
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}