#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size(),l=0,r=0,ans=0,arr[3]{};
        while (r<n){
            arr[s[r++]-'a']++;
            while (arr[0]>0&&arr[1]>0&&arr[2]>0){
                arr[s[l]-'a']--;
                ++l;
            }
            ans+=l;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}