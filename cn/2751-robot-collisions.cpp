#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        vector<int>ans_sub(n),ans;
        stack<array<int,3>>s;
        vector<array<int,4>>v(n);
        for (int i = 0; i < n; ++i) {
            v[i]={positions[i],healths[i],directions[i],i};
        }
        ranges::sort(v);
        for (int i = 0; i < n; ++i) {
            if (v[i][2]=='L'){
                if (s.empty()||s.top()[2]=='L'){
                    s.push({v[i][1],v[i][3],'L'});
                }else{
                    int health=v[i][1];
                    while (!s.empty()&&health&&s.top()[2]=='R'){
                        if (health>s.top()[0]){
                            health--;
                            s.pop();
                        }else if (health<s.top()[0]){
                            health=0;
                            s.top()[0]--;
                        }else{
                            health=0;
                            s.pop();
                        }
                    }
                    if (health)
                        s.push({health,v[i][3],'L'});
                }
            }else{
                s.push({v[i][1],v[i][3],'R'});
            }
        }
        while (!s.empty()){
            ans_sub[s.top()[1]]=s.top()[0];
            s.pop();
        }
        for (int i = 0; i < n; ++i) {
            if (ans_sub[i])
                ans.push_back(ans_sub[i]);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}