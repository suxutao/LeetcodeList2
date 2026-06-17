#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool f(unordered_map<int, int> &m) {
        if (m.size() == 1 && m.begin()->second == 1)
            return true;
        if (m.size() != 2)
            return false;
        vector<int> v;
        for (auto &item: m) {
            v.push_back(item.first);
        }
        return v[0] == 2 * v[1] || v[1] == 2 * v[0];
    }

    int getLength(vector<int> &nums) {
        int n = nums.size(), ans = 1;
        for (int i = 0; i < n; ++i) {
            unordered_map<int, int> m, m2;
            for (int j = i; j < n; ++j) {
                if (m.contains(nums[j])) {
                    m2[m[nums[j]]]--;
                    if (m2[m[nums[j]]] == 0)
                        m2.erase(m[nums[j]]);
                }
                m2[m[nums[j]] + 1]++;
                m[nums[j]]++;
                if (f(m2))
                    ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}