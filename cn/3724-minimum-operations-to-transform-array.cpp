#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        ll n=nums1.size(),ans=0,gap=INT_MAX;
        for (int i = 0; i < n; ++i) {
            ans+=abs(nums1[i]-nums2[i]);
            if (nums2.back()>=nums1[i]&&nums2.back()<=nums2[i]||nums2.back()<=nums1[i]&&nums2.back()>=nums2[i]){
                gap=0;
            }else{
                gap=min<ll>({gap,abs(nums1[i]-nums2[n]),abs(nums2[i]-nums2[n])});
            }
        }
        return ans+gap+1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}