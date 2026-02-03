#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size(),temp,jie=0;
        if (nums[0]>=nums[1]||nums[n-2]>=nums[n-1])
            return false;
        for (int i = 0; i < n - 1; ++i) {
            temp=nums[i+1]-nums[i];
            if (temp>0){
                if (jie==1){
                    jie++;
                }
            }else if (temp<0){
                if (jie==0){
                    jie++;
                }else if (jie==2){
                    return false;
                }
            }else{
                return false;
            }
        }
        return jie==2;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}