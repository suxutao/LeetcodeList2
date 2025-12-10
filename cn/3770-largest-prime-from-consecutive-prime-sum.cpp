#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<bool>is_prime;
    vector<int>prime;
    void init(int n){
        is_prime.resize(n+1);
        for (int i = 2; i <= n; ++i) {
            if (!is_prime[i])
                prime.push_back(i);
            for (auto &j: prime){
                if (i*j>n) break;
                is_prime[i*j]=1;
                if (i%j==0) break;
            }
        }
    }
    int largestPrime(int n) {
        if (n==1)
            return 0;
        int sum=0,ans;
        init(n);
        for (int i = 0; i < prime.size()&&sum<=n; ++i) {
            sum+=prime[i];
            if (sum<=n&&!is_prime[sum])
                ans=sum;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}