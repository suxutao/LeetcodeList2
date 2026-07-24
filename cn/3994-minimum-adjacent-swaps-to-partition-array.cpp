#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    const int N=1e9+7;
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int n=nums.size();
        ll ans=0,c2=0,c1=0;
        for (int i = 0; i < n; ++i) {
            if (nums[i]<a){
                ans+=c1+c2;
            }else if (nums[i]>b){
                c2++;
            }else{
                c1++;
                ans+=c2;
            }
        }
        return ans%N;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}