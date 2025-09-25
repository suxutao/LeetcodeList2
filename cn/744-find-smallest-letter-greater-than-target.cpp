#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l=0,r=letters.size();
        while (l<r){
            int mid=(l+r)>>1;
            if (letters[mid]<=target){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        return l==letters.size()?letters[0]:letters[l];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}