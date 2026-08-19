#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int> > &reservedSeats) {
        int ans = 0;
        unordered_map<int, array<bool, 10> > m;
        for (auto &r: reservedSeats) {
            m[r[0]][r[1] - 1] = 1;
        }
        ans += (n - m.size()) * 2;
        for (auto &[row,col]: m) {
            bool a = 1, b = 1, c = 1;
            for (int i = 1; i < 5; ++i) {
                if (col[i]) {
                    a = false;
                    break;
                }
            }
            for (int i = 5; i < 9; ++i) {
                if (col[i]) {
                    b = false;
                    break;
                }
            }
            for (int i = 3; i < 7; ++i) {
                if (col[i]) {
                    c = false;
                    break;
                }
            }
            if (a && b) {
                ans += 2;
            } else if (a || b || c) {
                ans++;
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    return 0;
}
