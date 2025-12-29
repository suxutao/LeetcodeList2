#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    unordered_set<string> vis;
    unordered_map<int, string> m;
    vector<string> vs;

    bool dfs(int x, int y) {
        if (x < 0)
            return true;
        if (vis.contains(vs[x]))
            return false;
        if (y == x + 1) {
            vis.contains(vs[x]);
            return dfs(x - 1, 0);
        }
        for (auto &i: m[vs[x + 1][y] * 'A' + vs[x + 1][y + 1]]) {
            vs[x].push_back(i);
            if (dfs(x,y+1))
                return true;
            vs[x].pop_back();
        }
        return false;
    }

    bool pyramidTransition(string bottom, vector<string> &allowed) {
        int n = bottom.size();
        vs.resize(n);
        vs[n - 1] = move(bottom);
        for (auto &i: allowed) {
            m[i[0] * 'A' + i[1]].push_back(i[2]);
        }
        return dfs(n - 2, 0);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}