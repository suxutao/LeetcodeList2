#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;

    long long minNumberOfSeconds(int mountainHeight, vector<int> &workerTimes) {
        ll n = workerTimes.size(), ans = 0;
        priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<>> q;
        unordered_map<ll, ll> m;
        for (int i = 0; i < n; ++i) {
            q.push({workerTimes[i], workerTimes[i], i});
            m[i] = 2;
        }
        while (mountainHeight) {
            auto [a, b, c] = q.top();
            q.pop();
            ans = max(ans, a);
            a += b * m[c]++;
            q.push({a, b, c});
            mountainHeight--;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}