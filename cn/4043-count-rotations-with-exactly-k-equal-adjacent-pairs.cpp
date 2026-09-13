#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size(), sum = 0, ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1])
                sum++;
        }
        if (sum == k)
            ans++;
        sum += s[0] == s[n - 1];
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1])
                sum--;
            if (sum == k)
                ans++;
            if (s[i] == s[i + 1])
                sum++;
        }
        return ans;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


int main() {
    return 0;
}
