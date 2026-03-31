#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        string ans(n + m - 1, '?');
        for (int i = 0; i < n; ++i) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; ++j) {
                    if (ans[i + j] != '?' && ans[i + j] != str2[j])
                        return "";
                    ans[i + j] = str2[j];
                }
            }
        }
        string old_str(ans);
        for (int i = 0; i < n + m - 1; ++i) {
            if (ans[i] == '?')
                ans[i] = 'a';
        }
        for (int i = 0; i < n; ++i) {
            if (str1[i] == 'F' && ans.substr(i, m) == str2) {
                bool update = false;
                for (int j = m - 1; j >= 0; --j) {
                    if (old_str[i + j] == '?') {
                        ans[i + j] = 'b';
                        update = true;
                        break;
                    }
                }
                if (!update)
                    return "";
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}