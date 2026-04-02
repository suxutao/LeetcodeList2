#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int arr[7]{0, 0, 0, 0, 1, 1, 1};

    int count(int n) {
        int ans = 0;
        while (n) {
            n /= 10;
            ans++;
        }
        return ans;
    }

    int countCommas(int n) {
        int c = count(n), ans = 0;
        for (int i = 4; i < c; ++i) {
            ans += arr[i] * 9 * pow(10, i - 1);
        }
        ans += arr[c] * (n - pow(10, c - 1) + 1);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}