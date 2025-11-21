#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size(),arr[26][2]{},ans=0;
        for (int i = 0; i < n; ++i) {
            if (arr[s[i]-'a'][0]){
                arr[s[i]-'a'][1]=i+1;
            }else{
                arr[s[i]-'a'][0]=i+1;
            }
        }
        for (int i = 0; i < 26; ++i) {
            if (arr[i][0]&&arr[i][1]){
                unordered_set<int>se{s.begin()+arr[i][0],s.begin()+arr[i][1]-1};
                ans+=se.size();
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}