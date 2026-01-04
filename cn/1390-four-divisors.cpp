#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int cal(int x){
        int n= sqrt(x);
        vector<int>v;
        if (n*n==x)
            return 0;
        for (int i = 1; i < sqrt(x); ++i) {
            if (x%i==0){
                v.push_back(i);
                v.push_back(x/i);
            }
            if (v.size()>4)
                return 0;
        }
        return v.size()==4?v[0]+v[1]+v[2]+v[3]:0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans=0,n=nums.size();
        for (int i = 0; i < n; ++i) {
            ans+=cal(nums[i]);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}