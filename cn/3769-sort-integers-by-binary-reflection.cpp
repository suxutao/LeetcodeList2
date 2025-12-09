#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int fan(int x){
        int ans=0;
        while (x){
            ans=ans*2+(x&1);
            x>>=1;
        }
        return ans;
    }
    vector<int> sortByReflection(vector<int>& nums) {
        ranges::sort(nums,[&](int a,int b)->bool{
            int fa=fan(a),fb=fan(b);
            if (fa==fb)
                return a<b;
            return fa<fb;
        });
        return nums;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}