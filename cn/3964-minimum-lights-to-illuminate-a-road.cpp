#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minLights(vector<int> &lights) {
        int n = lights.size(), ans = 0;
        vector<array<int, 2>> v, a;
        for (int i = 0; i < n; ++i) {
            if (lights[i]) {
                v.push_back({max(0, i - lights[i]), min(n - 1, i + lights[i])});
            }
        }
        if (v.empty())
            return ceil(n/3.);
        ranges::sort(v);

        int l = v[0][0], r = v[0][1];
        for (int i = 1; i < v.size(); ++i) {
            if (v[i][0] <= r) {
                r = max(r, v[i][1]);
            } else {
                a.push_back({l, r});
                l = v[i][0], r = v[i][1];
            }
        }
        a.push_back({l, r});
        ans += ceil(a[0][0] / 3.) + ceil((n - 1 - a.back()[1]) / 3.);
        for (int i = 1; i < a.size(); ++i) {
            ans += ceil((a[i][0] - a[i - 1][1] - 1) / 3.);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}