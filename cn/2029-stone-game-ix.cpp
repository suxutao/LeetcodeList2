#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    bool check(int n, int cnt[3]) {
        if (cnt[1] == 0) {
            return false;
        }
        cnt[1]--;
        int rounds = 1 + min(cnt[1], cnt[2]) * 2 + cnt[0];
        if (cnt[1] > cnt[2]) {
            rounds++;
        }
        return rounds < n && rounds % 2 > 0;
    }

public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3]{};
        for (int x : stones) {
            cnt[x % 3]++;
        }

        int n = stones.size();
        int cnt2[3] = {cnt[0], cnt[2], cnt[1]};
        return check(n, cnt) || check(n, cnt2);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}