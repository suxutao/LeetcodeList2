#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int climbStairs(int n) {
        int arr[50]{0,1,2};
        for (int i = 3; i <= n; ++i) {
            arr[i]=arr[i-1]+arr[i-2];
        }
        return arr[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}