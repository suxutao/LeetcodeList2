#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Tree {
    int n;
    vector<int> v;

public:
    Tree(int n) : n(n), v(n + 2) {
    }

    void add(int x, int d) {
        while (x <= n) {
            v[x] += d;
            x += x & -x;
        }
    }

    int query(int x) {
        int res = 0;
        while (x > 0) {
            res += v[x];
            x -= x & -x;
        }
        return res;
    }

    int bigger(int x) {
        return query(n) - query(x);
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int> &nums) {
        int n = nums.size();
        vector<int> v1, v2, ncopy(nums);
        Tree t1(n), t2(n);
        unordered_map<int, int> r;
        ranges::sort(ncopy);
        ncopy.erase(ranges::unique(ncopy).begin(), ncopy.end());
        for (int i = 0; i < ncopy.size(); ++i) {
            r[ncopy[i]] = i + 1;
        }
        v1.push_back(nums[0]);
        v2.push_back(nums[1]);
        t1.add(r[nums[0]], 1);
        t2.add(r[nums[1]], 1);
        for (int i = 2; i < n; ++i) {
            int c1 = t1.bigger(r[nums[i]]), c2 = t2.bigger(r[nums[i]]);
            if (c1 > c2) {
                v1.push_back(nums[i]);
                t1.add(r[nums[i]], 1);
            } else if (c1 < c2) {
                v2.push_back(nums[i]);
                t2.add(r[nums[i]], 1);
            } else {
                if (v1.size() <= v2.size()) {
                    v1.push_back(nums[i]);
                    t1.add(r[nums[i]], 1);
                } else {
                    v2.push_back(nums[i]);
                    t2.add(r[nums[i]], 1);
                }
            }
        }
        for (int i = 0; i < v2.size(); ++i) {
            v1.push_back(v2[i]);
        }
        return v1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    return 0;
}
