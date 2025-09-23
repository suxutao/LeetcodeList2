#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    int compareVersion(string version1, string version2) {
        ll n1=version1.size(),n2=version2.size(),a=0;
        vector<ll>v1,v2;
        for (int i = 0; i < n1; ++i) {
            if (version1[i]=='.'){
                v1.push_back(a);
                a=0;
            }else{
                a=a*10+version1[i]-'0';
            }
        }
        v1.push_back(a);
        a=0;
        for (int i = 0; i < n2; ++i) {
            if (version2[i]=='.'){
                v2.push_back(a);
                a=0;
            }else{
                a=a*10+version2[i]-'0';
            }
        }
        v2.push_back(a);
        if (v1.size()<v2.size()){
            int sz=v2.size()-v1.size();
            for (int i = 0; i < sz; ++i) {
                v1.push_back(0);
            }
        }else{
            int sz=v1.size()-v2.size();
            for (int i = 0; i < sz; ++i) {
                v2.push_back(0);
            }
        }
        for (int i = 0; i < v1.size(); ++i) {
            if (v1[i]<v2[i])
                return -1;
            else if (v1[i]>v2[i])
                return 1;
        }
        return 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}