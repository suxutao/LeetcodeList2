#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool f(long long n, int x) {
        int a=n%10;
        if (a!=x)
            return false;
        while (n){
            a=n%10;
            n/=10;
        }
        return a==x;
    }

    int countValidSubarrays(vector<int> &nums, int x) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            long long sum = 0;
            for (int j = i; j < n; ++j) {
                sum += nums[j];
                ans += f(sum, x);
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}