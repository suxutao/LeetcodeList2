#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        char c=s[0];
        int n=s.size(),cnt=1,ans=0;
        vector<array<int,2>>v;
        for (int i = 1; i < n; ++i) {
            if (s[i]!=c){
                if (c=='1')
                    ans+=cnt;
                v.push_back({c,cnt});
                c=s[i];
                cnt=1;
            }else{
                cnt++;
            }
        }
        v.push_back({c,cnt});
        if (c=='1')
            ans+=cnt;
        if (v.size()<=2){
            return ans;
        }
        if (v.size()==3){
            if (v[0][0]=='1')
                return ans;
            else
                return n;
        }
        int sum=0;
        for (int i = v[0][0]=='0'?2:3; i < v.size(); i+=2) {
            sum=max(sum,v[i][1]+v[i-2][1]);
        }
        return ans+sum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}