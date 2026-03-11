#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int ans=-1,n=capacity.size(),mn=INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (capacity[i]>=itemSize&&capacity[i]<mn){
                ans=i;
                mn=capacity[i];
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}