#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        ranges::reverse(energy);
        vector<int>mx(k),sum(k);
        for (int i = 0; i < n; ++i) {
            if (i<k)
                mx[i]=sum[i]=energy[i];
            else{
                sum[i%k]+=energy[i];
                mx[i%k]=max(mx[i%k],sum[i%k]);
            }
        }
        return ranges::max(mx);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}