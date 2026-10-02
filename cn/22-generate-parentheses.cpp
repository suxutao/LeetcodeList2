#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int n;
    string s;
    vector<string>v;
    void dfs(int l,int r) {
        if (l>n||r>n) {
            return;
        }
        if (r==n) {
            v.push_back(s);
            return;
        }
        s.push_back('(');
        dfs(l+1,r);
        s.pop_back();
        if (l!=r) {
            s.push_back(')');
            dfs(l,r+1);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        this->n=n;
        dfs(0,0);
        return v;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}