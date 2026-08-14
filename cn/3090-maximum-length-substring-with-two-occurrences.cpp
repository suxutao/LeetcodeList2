#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size(),l=0,r=0,ans=0;
        int arr[26]{};
        while (r<n){
            if (++arr[s[r]-'a']>2){
                while (arr[s[r]-'a']>2){
                    --arr[s[l++]-'a'];
                }
            }
            ans=max(ans,r-l+1);
            ++r;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}