#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        int n=queries.size();
        vector<int>ans(n);
        unordered_map<string,int>m;
        string s,t;
        for (auto &i: chunks){
            s+=i;
        }
        stringstream ss(s);
        while (getline(ss,t,' ')){
            string temp;
            for (int i = 0; i < t.size(); ++i) {
                if (t[i]=='-'){
                    if (i&&i<t.size()-1&&t[i-1]!='-'&&t[i+1]!='-'){
                        temp.push_back('-');
                    }else{
                        if (!temp.empty())
                            ++m[temp];
                        temp.clear();
                    }
                }else{
                    temp.push_back(t[i]);
                }
            }
            if (!temp.empty())
                ++m[temp];
        }
        for (int i = 0; i < n; ++i) {
            ans[i]=m[queries[i]];
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}