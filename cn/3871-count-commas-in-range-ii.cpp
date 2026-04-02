#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    ll arr[17]{0, 0, 0, 0, 1, 1, 1,2,2,2,3,3,3,4,4,4,5};

    int count(ll n) {
        int ans = 0;
        while (n) {
            n /= 10;
            ans++;
        }
        return ans;
    }

    ll countCommas(ll n) {
        ll c = count(n), ans = 0;
        for (int i = 4; i < c; ++i) {
            ans += arr[i] * 9 * pow(10, i - 1);
        }
        ans += arr[c] * (n - pow(10, c - 1) + 1);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}