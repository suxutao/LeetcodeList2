#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    struct Node {
        Node* son[26]{};
        int min_len = INT_MAX;
        int best_index;
    };

    void clear(Node* node) {
        for (int i = 0; i < 26; i++) {
            if (node->son[i]) {
                clear(node->son[i]);
            }
        }
        delete node;
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int n=wordsContainer.size(),nq=wordsQuery.size();
        Node* root = new Node();
        vector<int>ans(nq);
        for (int i = 0; i < n; ++i) {
            string&s=wordsContainer[i];
            Node*p=root;
            if (s.size()<p->min_len){
                p->min_len=s.size();
                p->best_index=i;
            }
            for (int j = s.size() - 1; j >= 0; --j) {
                if (!p->son[s[j]-'a']){
                    p->son[s[j]-'a']=new Node();
                }
                p=p->son[s[j]-'a'];
                if (s.size()<p->min_len){
                    p->min_len=s.size();
                    p->best_index=i;
                }
            }
        }
        for (int i = 0; i < nq; ++i) {
            string&s=wordsQuery[i];
            Node*p=root;
            for (int j = s.size() - 1; j >= 0; --j) {
                if (!p->son[s[j]-'a']){
                    ans[i]=p->best_index;
                    break;
                }else{
                    p=p->son[s[j]-'a'];
                    ans[i]=p->best_index;
                }
            }
        }
        clear(root);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}