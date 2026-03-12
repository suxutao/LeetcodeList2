#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
struct union_set {
    vector<int> fa;

    union_set(int n) : fa(n) {
        for (int i = 0; i < n; ++i) {
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
            fa[x] = y;
    }

    bool link(int x, int y) {
        x = find(x);
        y = find(y);
        return x == y;
    }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>> &edges, int k) {
        int mn = INT_MAX, bian = 0;
        union_set us(n);
        vector<int>res;
        vector<vector<int>> v;
        for (auto &i: edges) {
            if (i[3] == 1) {
                if (us.link(i[0], i[1]))
                    return -1;
                mn = min(mn, i[2]);
                us.merge(i[0], i[1]);
                ++bian;
            } else {
                v.push_back(i);
            }
        }
        if (bian == n - 1)
            return mn;
        ranges::sort(v, [&](auto &a, auto &b) {
            return a[2] > b[2];
        });
        for (auto &i: v) {
            if (!us.link(i[0],i[1])){
                us.merge(i[0],i[1]);
                bian++;
                res.push_back(i[2]);
            }
            if (bian==n-1){
                break;
            }
        }
        if (bian<n-1)
            return -1;
        ranges::reverse(res);
        for (int i = 0; i < min<int>(k,res.size()); ++i) {
            res[i]<<=1;
        }
        res.push_back(mn);
        ranges::sort(res);
        return res[0];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}