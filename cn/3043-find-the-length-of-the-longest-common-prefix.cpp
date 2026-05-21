#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2) {
        unordered_set<int> st;
        for (int x : arr1) {
            for (; x > 0; x /= 10) {
                st.insert(x);
            }
        }

        int mx = 0;
        for (int x : arr2) {
            while (x > 0 && !st.contains(x)) {
                x /= 10;
            }
            mx = max(mx, x);
        }
        return mx ? to_string(mx).length() : 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}