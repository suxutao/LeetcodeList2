#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>> &sources) {
        int arr[4][2]{{0,  1},
                      {1,  0},
                      {-1, 0},
                      {0,  -1}};
        vector<vector<int>> ans(n, vector<int>(m));
        vector<vector<bool>> vis(n, vector<bool>(m));
        queue<array<int, 2>> q;
        for (auto &i: sources) {
            ans[i[0]][i[1]] = i[2];
            vis[i[0]][i[1]] = 1;
            q.push({i[0], i[1]});
        }
        while (!q.empty()) {
            int sz = q.size();
            vector<array<int, 3>> v;
            for (int i = 0; i < sz; ++i) {
                auto [x, y] = q.front();
                int color = ans[x][y];
                q.pop();
                for (auto [a, b]: arr) {
                    a += x;
                    b += y;
                    if (a >= 0 && a < n && b >= 0 && b < m && !vis[a][b]) {
                        v.push_back({a, b, color});
                    }
                }
            }
            ranges::sort(v, greater<>());
            for (int i = 0; i < v.size(); ++i) {
                if (ans[v[i][0]][v[i][1]] < v[i][2]) {
                    ans[v[i][0]][v[i][1]] = v[i][2];
                    q.push({v[i][0], v[i][1]});
                    vis[v[i][0]][v[i][1]] = 1;
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