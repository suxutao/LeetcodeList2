#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Bank {
    using ll = long long;
public:
    int n;
    vector<ll>balance;
    Bank(vector<long long>& balance):balance(balance) {
        n=balance.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account1>n||account1<=0||account2>n||account2<=0){
            return false;
        }
        if (balance[account1-1]>=money){
            balance[account1-1]-=money;
            balance[account2-1]+=money;
            return true;
        }else{
            return false;
        }
    }
    
    bool deposit(int account, long long money) {
        if (account>n||account<=0){
            return false;
        }
        balance[account-1]+=money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (account>n||account<=0||balance[account-1]<money){
            return false;
        }
        balance[account-1]-=money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}