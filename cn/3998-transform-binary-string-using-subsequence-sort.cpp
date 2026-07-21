#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<bool> transformStr(string s, vector<string> &strs) {
        int n = s.size(), nq = strs.size(), n0 = 0, n1 = 0;
        vector<bool> ans(nq);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                n0++;
            } else {
                n1++;
            }
        }
        for (int i = 0; i < nq; ++i) {
            int q0 = 0, q1 = 0;
            auto &str = strs[i];
            for (int j = 0; j < n; ++j) {
                if (str[j] == '0') {
                    q0++;
                } else if (str[j] == '1') {
                    q1++;
                }
                if (q0 > n0 || q1 > n1)
                    break;
            }
            if (q0 > n0 || q1 > n1)
                continue;
            q0 = n0 - q0;
            for (int j = 0; j < n; ++j) {
                if (str[j] == '?') {
                    if (q0 > 0) {
                        q0--;
                        str[j] = '0';
                    } else {
                        str[j] = '1';
                    }
                }
            }
            bool b = true;
            int c = 0, cq = 0;
            for (int j = n - 1; j >= 0; --j) {
                c += s[j] == '1';
                cq += str[j] == '1';
                if (c > cq) {
                    b = false;
                    break;
                }
            }
            ans[i] = b;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}