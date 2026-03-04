#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int jie(int n){
        int ans=1;
        for (int i = 1; i <= n; ++i) {
            ans*=i;
        }
        return ans;
    }
    bool isDigitorialPermutation(int n) {
        int sum=0;
        unordered_map<int,int>m;
        while (n){
            sum+=jie(n%10);
            ++m[n%10];
            n/=10;
        }
        while (sum){
            --m[sum%10];
            if (m[sum%10]==0)
                m.erase(sum%10);
            sum/=10;
        }
        return m.empty();
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}