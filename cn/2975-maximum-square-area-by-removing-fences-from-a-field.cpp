#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    const int N=1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        ll mx=0;
        unordered_set<ll>s;
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        ranges::sort(hFences);
        ranges::sort(vFences);
        for (int i = 1; i < hFences.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                s.insert(hFences[i]-hFences[j]);
            }
        }
        for (int i = 1; i < vFences.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                ll t=vFences[i]-vFences[j];
                if (s.contains(t)){
                    mx=max(mx,t);
                }
            }
        }
        return mx==0?-1:mx*mx%N;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}