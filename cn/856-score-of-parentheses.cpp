#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    unordered_map<string, int> m;

    int scoreOfParentheses(string s) {
        if (s == "()")
            return 1;
        if (m.contains(s))
            return m[s];
        bool b = false;
        int n = s.size(), l = 0, r = 0, pre = 0, ans = 0;
        for (int i = 1; i < n - 1; ++i) {
            s[i] == '(' ? l++ : r++;
            if (r > l) {
                b = true;
                break;
            }
        }
        l = 0, r = 0;
        if (b) {
            for (int i = 0; i < n; ++i) {
                s[i] == '(' ? l++ : r++;
                if (l == r) {
                    string temp = s.substr(pre, i - pre + 1);
                    ans += scoreOfParentheses(temp);
                    pre = i + 1;
                }
            }
            return m[s] = ans;
        } else {
            return m[s] = 2 * scoreOfParentheses(s.substr(1, n - 2));
        }
    }
};

//leetcode submit region end(Prohibit modification and deletion)


int main() {
    return 0;
}
