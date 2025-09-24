#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;

    string fractionToDecimal(ll numerator, ll denominator) {
        string ans, pre;
        unordered_map<ll, int> m;
        if (numerator * denominator < 0)
            pre = '-';
        numerator = abs(numerator);
        denominator = abs(denominator);
        ll shang = numerator / denominator, yu = numerator % denominator;
        pre += to_string(shang) + ".";
        m[yu] = 0;
        if (yu) {
            while (yu) {
                shang = yu * 10 / denominator;
                yu = yu * 10 % denominator;
                ans.push_back(shang + '0');
                if (m.contains(yu)) {
                    if (m[yu] == 0)
                        ans = "(" + ans + ")";
                    else
                        ans = ans.substr(0, m[yu]) + "(" + ans.substr(m[yu]) + ")";
                    break;
                }
                m[yu] = ans.size();
            }
        } else {
            pre.pop_back();
        }
        return pre + ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}