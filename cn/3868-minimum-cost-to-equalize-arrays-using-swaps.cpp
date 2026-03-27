#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),ans=0;
        unordered_map<int,int>m,m1;
        for (int i = 0; i < n; ++i) {
            ++m1[nums1[i]];
            ++m[nums1[i]];
            ++m[nums2[i]];
        }
        for (auto &[a,b]: m){
            if (b&1)
                return -1;
            ans+=abs(b/2-m1[a]);
        }
        return ans/2;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}