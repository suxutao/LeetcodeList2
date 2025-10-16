#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n=nums.size(),t=n,val=0;
        unordered_map<int,int>m;
        for (int i = 0; i < n; ++i) {
           m[(nums[i]%value+value)%value]++;
        }
        for (int i = 0; i < value; ++i) {
            if (m[i]<t){
                t=m[i];
                val=i;
            }
        }
        return val+value*m[val];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}