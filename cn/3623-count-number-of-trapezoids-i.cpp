#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    const int N = 1e9 + 7;

    int countTrapezoids(vector<vector<int>> &points) {
        unordered_map<int, ll> m;
        for (auto &v: points) {
            ++m[v[1]];
        }
        vector<ll> v;
        for (auto &[a, b]: m) {
            v.push_back(b * (b - 1) / 2 % N);
        }
        ll sum = accumulate(v.begin(), v.end(), 0ll), ans = 0;
        for (int i = 0; i < v.size(); ++i) {
            sum -= v[i];
            ans = (ans + sum % N * v[i] % N) % N;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}