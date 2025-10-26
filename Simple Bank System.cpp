class Bank {
public:
    vector<long long> amount;
    int n;
    Bank(vector<long long>& balance) {
        amount = balance;
        n = balance.size(); 
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1-1>n || account2-1>n ) return false;
        if(amount[account1-1]<money) return false;
        amount[account1-1] -= money;
        amount[account2-1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(account-1>n) return false;
        amount[account-1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account-1>n) return false;
        if(amount[account-1]<money) return false;
        amount[account-1] -= money;
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
