#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int digitFrequencyScore(int n) {
        int ans=0;
        unordered_map<int,int>m;
        while (n){
            m[n%10]++;
            n/=10;
        }
        for (auto &[a,b]: m){
            ans+=a*b;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}