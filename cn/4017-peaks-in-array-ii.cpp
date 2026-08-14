#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
struct Data {
    long long cnt;
    int pre, suf, len;
    bool has_peak;
};

class SegmentTree {
    int n;
    vector<Data> tree;

    Data merge_data(const Data& a, const Data& b) const {
        long long cnt = a.cnt + b.cnt + 1LL * a.len * b.len - 1LL * a.suf * b.pre;
        int pre = a.has_peak ? a.pre : a.len + b.pre;
        int suf = b.has_peak ? b.suf : b.len + a.suf;
        return {cnt, pre, suf, a.len + b.len, a.has_peak || b.has_peak};
    }

    void maintain(int node) {
        tree[node] = merge_data(tree[node * 2], tree[node * 2 + 1]);
    }

    void build(const vector<int>& a, int node, int l, int r) {
        if (l == r) {
            bool has_peak = 0 < l && l < n - 1 && a[l - 1] < a[l] && a[l] > a[l + 1];
            tree[node] = {0, 1, 1, 1, has_peak};
            return;
        }
        int m = (l + r) >> 1;
        build(a, node * 2, l, m);
        build(a, node * 2 + 1, m + 1, r);
        maintain(node);
    }

    void update(int node, int l, int r, int i, bool has_peak) {
        if (l == r) {
            tree[node].has_peak = has_peak;
            return;
        }
        int m = (l + r) >> 1;
        if (i <= m) {
            update(node * 2, l, m, i, has_peak);
        } else {
            update(node * 2 + 1, m + 1, r, i, has_peak);
        }
        maintain(node);
    }

    Data query(int node, int l, int r, int ql, int qr) const {
        if (ql <= l && r <= qr) {
            return tree[node];
        }
        int m = (l + r) >> 1;
        if (qr <= m) {
            return query(node * 2, l, m, ql, qr);
        }
        if (ql > m) {
            return query(node * 2 + 1, m + 1, r, ql, qr);
        }
        return merge_data(query(node * 2, l, m, ql, qr), query(node * 2 + 1, m + 1, r, ql, qr));
    }

public:
    SegmentTree(const vector<int>& a) : n(a.size()), tree(2 << bit_width(a.size() - 1)) {
        build(a, 1, 0, n - 1);
    }

    void update(int i, bool has_peak) {
        update(1, 0, n - 1, i, has_peak);
    }

    long long query(int ql, int qr) const {
        return query(1, 0, n - 1, ql, qr).cnt;
    }
};

class Solution {
public:
    vector<long long> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        SegmentTree t(nums);
        vector<long long> ans;
        for (auto& q : queries) {
            if (q[0] == 1) {
                ans.push_back(t.query(q[1], q[2]));
                continue;
            }
            int i = q[1];
            nums[i] = q[2];
            for (int j = max(i - 1, 1); j <= min(i + 1, n - 2); j++) {
                bool has_peak = nums[j - 1] < nums[j] && nums[j] > nums[j + 1];
                t.update(j, has_peak);
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}