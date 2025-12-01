#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int rec(int x){
        string s=to_string(x);
        reverse(s.begin(), s.end());
        return stoi(s);
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size(),ans=INT_MAX;
        unordered_map<int,int>m;
        for (int i = n - 1; i >= 0; --i) {
            int r=rec(nums[i]);
            if (m.contains(r)){
                ans=min(ans,m[r]-i);
            }
            m[nums[i]]=i;
        }
        return ans==INT_MAX?-1:ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}