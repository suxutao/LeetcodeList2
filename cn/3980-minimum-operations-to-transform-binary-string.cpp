#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minOperations(string s1, string s2) {
        if (s1=="1"&&s2=="0")
            return -1;
        int n=s1.size();
        int T[2][2][2][2]{0,1,1,2,2,0,3,1,2,3,0,1,1,2,2,0};
        vector<int>dp(n+1);
        unordered_map<int,int>m;
        if (s1[0]=='1'&&s2[0]=='0')
            dp[1]=2;
        if (s1[0]=='0'&&s2[0]=='1')
            dp[1]=1;
        for (int i = 2; i <= n; ++i) {
            int t=T[s1[i-2]-'0'][s1[i-1]-'0'][s2[i-2]-'0'][s2[i-1]-'0'];
            if (s1[i-1]==s2[i-1]){
                dp[i]=min(dp[i-1],t+dp[i-2]);
            }else if (s1[i-1]=='0'&&s2[i-1]=='1'){
                dp[i]=min(1+dp[i-1],t+dp[i-2]);
            }else{
                dp[i]=t+dp[i-2];
            }
        }
        return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}