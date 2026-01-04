#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minAllOneMultiple(int k) {
        int n=1%k,ans=1;
        unordered_set<int>s;
        while (n){
            if (s.contains(n))
                return -1;
            s.insert(n);
            n=(n*10+1)%k;
            ans++;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}