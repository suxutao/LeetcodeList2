#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        ll sum=0;
        for (int i = 1; i <= n; ++i) {
            sum+=i;
        }
        if (sum<target||-sum>target)
            return {};
        ll t=(sum-target)/2;
        vector<int>ans;
        unordered_set<int>s;
        for (int i = n; i&&t; --i) {
            if (t>i){
                s.insert(i);
                ans.push_back(-i);
                t-=i;
            }else{
                s.insert(t);
                ans.push_back(-t);
                break;
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (!s.contains(i))
                ans.push_back(i);
        }
        ll sum_ans=accumulate(ans.begin(), ans.end(),0ll);
        return sum_ans!=target?(vector<int>){}:ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution().lexSmallestNegatedPerm(3,0);
    return 0;
}