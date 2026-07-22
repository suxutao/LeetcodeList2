#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
struct Pair { int l, r; }; // 左闭右开

class SparseTable {
    vector<vector<int>> st;

public:
    SparseTable(vector<Pair>& a) {
        int n = a.size() - 1;
        int w = bit_width(unsigned(n));
        st.resize(w, vector<int>(n));
        for (int j = 0; j < n; j++) {
            st[0][j] = a[j].r - a[j].l + a[j + 1].r - a[j + 1].l;
        }
        for (int i = 1; i < w; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    // 查询区间最大值，[l,r) 左闭右开
    int query(int l, int r) const {
        if (l >= r) {
            return 0;
        }
        int k = bit_width(unsigned(r - l)) - 1;
        return max(st[k][l], st[k][r - (1 << k)]);
    }
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int total1 = 0;
        vector<Pair> a = {{-1, -1}}; // 哨兵
        int start = 0;
        for (int i = 0; i < n; i++) {
            if (i == n - 1 || s[i] != s[i + 1]) {
                if (s[i] == '1') {
                    total1 += i - start + 1;
                } else {
                    a.emplace_back(start, i + 1); // 左闭右开
                }
                start = i + 1;
            }
        }
        a.emplace_back(n + 1, n + 1); // 哨兵

        auto merge = [](int x, int y) {
            return x > 0 && y > 0 ? x + y : 0;
        };

        SparseTable st(a);
        vector<int> ans(queries.size());
        for (int qi = 0; qi < queries.size(); qi++) {
            int ql = queries[qi][0], qr = queries[qi][1] + 1; // 左闭右开
            int i = ranges::lower_bound(a, ql, {}, &Pair::l) - a.begin();
            int j = ranges::upper_bound(a, qr, {}, &Pair::r) - a.begin() - 1;
            int mx = 0;
            if (i <= j) { // [ql,qr) 中有完整的区间
                mx = max({
                                 st.query(i, j), // 相邻完整区间的长度之和的最大值
                                 merge(a[i - 1].r - ql, a[i].r - a[i].l), // 残缺区间 i-1 + 完整区间 i
                                 merge(qr - a[j + 1].l, a[j].r - a[j].l), // 残缺区间 j+1 + 完整区间 j
                         });
            } else if (i == j + 1) { // [ql,qr) 中有两个相邻的残缺区间
                mx = merge(a[i - 1].r - ql, qr - a[j + 1].l); // 残缺区间 i-1 + 残缺区间 j+1
            }
            ans[qi] = total1 + mx;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}