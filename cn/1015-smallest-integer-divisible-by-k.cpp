#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int ans=1,p=1;
        if (k==1) return 1;
        unordered_set<int>s{1};
        while (p){
            p=(p*10+1)%k;
            if (s.contains(p))
                return -1;
            s.insert(p);
            ans++;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}