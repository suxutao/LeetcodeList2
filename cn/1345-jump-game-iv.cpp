#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minJumps(vector<int> &arr) {
        int n = arr.size(), ans = 0;
        unordered_map<int, vector<int>> m;
        unordered_set<int> s;
        vector<bool> vis(n);
        queue<int> q;
        vis[0] = 1;
        q.push(0);
        for (int i = 0; i < n; ++i) {
            m[arr[i]].push_back(i);
        }
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                int f = q.front();
                q.pop();
                if (f == n - 1)
                    return ans;
                if (f && !vis[f - 1]) {
                    q.push(f - 1);
                    vis[f - 1] = 1;
                }
                if (f < n - 1 && !vis[f + 1]) {
                    q.push(f + 1);
                    vis[f + 1] = 1;
                }
                if (!s.contains(arr[f])) {
                    s.insert(arr[f]);
                    for (auto &j: m[arr[f]]) {
                        if (j != f && !vis[j]) {
                            q.push(j);
                            vis[j] = 1;
                        }
                    }
                }
            }
            ++ans;
        }
        return 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}