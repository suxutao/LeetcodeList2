#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool is_prime(int n){
        if (n==1)
            return false;
        for (int i = 2; i <= sqrt(n); ++i) {
            if (n%i==0)
                return false;
        }
        return true;
    }
    int sumOfPrimesInRange(int n) {
        string s = to_string(n);
        ranges::reverse(s);
        int r = stoi(s),ans=0;
        for (int i = min(r, n); i <= max(r, n); ++i) {
            if (is_prime(i))
                ans+=i;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}