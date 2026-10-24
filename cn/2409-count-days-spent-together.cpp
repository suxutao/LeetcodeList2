#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int arr[13]{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int f(string up, string down) {
        if (up > down)
            return 0;
        int ans = 0;
        int month_up = (up[0] - '0') * 10 + up[1] - '0';
        int month_down = (down[0] - '0') * 10 + down[1] - '0';
        int day_up = (up[3] - '0') * 10 + up[4] - '0';
        int day_down = (down[3] - '0') * 10 + down[4] - '0';
        for (int i = month_up; i < month_down; ++i) {
            ans += arr[i];
        }
        return ans + day_down - day_up + 1;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        string mx = max(arriveAlice, arriveBob);
        string mn = min(leaveAlice, leaveBob);
        return f(mx, mn);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    return 0;
}
