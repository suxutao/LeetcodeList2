#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    const int N = 1e9 + 7;

    int specialTriplets(vector<int> &nums) {
        int n = nums.size();
        ll ans = 0;
        unordered_map<int, int> m1, m2;
        for (int i = 1; i < n; ++i) {
            ++m1[nums[i]];
        }
        ++m2[nums[0]];
        for (int i = 1; i < n - 1; ++i) {
            --m1[nums[i]];
            ans = (ans + (ll) m1[nums[i] * 2] * m2[nums[i] * 2] % N) % N;
            ++m2[nums[i]];
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}