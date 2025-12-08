#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;

    long long maxPoints(vector<int> &technique1, vector<int> &technique2, int k) {
        int n = technique1.size();
        ll ans = 0;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; ++i) {
            v[i] = {technique1[i] - technique2[i], i};
        }
        ranges::sort(v, greater<>());
        for (int i = 0; i < k; ++i) {
            ans += technique1[v[i].second];
        }
        for (int i = k; i < n; ++i) {
            ans += max(technique1[v[i].second], technique2[v[i].second]);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}