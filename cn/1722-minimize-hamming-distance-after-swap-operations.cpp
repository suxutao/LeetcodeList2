#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    struct union_set {
        vector<int> fa;

        union_set(int n) : fa(n + 1) {
            for (int i = 0; i <= n; ++i) {
                fa[i] = i;
            }
        }

        int query(int x) {
            return fa[x] == x ? x : fa[x] = query(fa[x]);
        }

        void merge(int x, int y) {
            x = query(x);
            y = query(y);
            if (x != y)
                fa[x] = y;
        }
    };

    int minimumHammingDistance(vector<int> &source, vector<int> &target, vector<vector<int>> &allowedSwaps) {
        int n = source.size(), ans = 0;
        unordered_map<int, unordered_multiset<int>> m;
        union_set us(100000);
        for (auto &i: allowedSwaps) {
            us.merge(i[0], i[1]);
        }
        for (int i = 0; i < n; ++i) {
            m[us.query(i)].insert(source[i]);
        }
        for (int i = 0; i < n; ++i) {
            int q = us.query(i);
            if (!m[q].contains(target[i])) {
                ans++;
            } else {
                m[q].extract(target[i]);
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}