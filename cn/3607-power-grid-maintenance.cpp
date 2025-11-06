#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    struct uni {
        vector<int> fa;

        uni(int n) : fa(n + 1) {
            for (int i = 1; i <= n; ++i) {
                fa[i] = i;
            }
        }

        int find(int x) {
            return fa[x] == x ? x : fa[x] = find(fa[x]);
        }

        void merge(int x, int y) {
            x = find(x);
            y = find(y);
            if (x != y)
                fa[y] = x;
        }
    };

    vector<int> processQueries(int c, vector<vector<int>> &connections, vector<vector<int>> &queries) {
        uni u(c);
        unordered_map<int, set<int>> m;
        unordered_set<int> s;
        vector<int> ans;
        for (auto &con: connections) {
            u.merge(con[0], con[1]);
        }
        for (int i = 1; i <= c; ++i) {
            m[u.find(i)].insert(i);
        }
        for (auto &q: queries) {
            if (q[0] == 2) {
                s.insert(q[1]);
            } else {
                if (!s.contains(q[1])) {
                    ans.push_back(q[1]);
                    continue;
                }
                int t = u.find(q[1]);
                while (!m[t].empty() && s.contains(*m[t].begin())) {
                    m[t].erase(m[t].begin());
                }
                if (m[t].empty()) {
                    ans.push_back(-1);
                } else {
                    ans.push_back(*m[t].begin());
                }
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}