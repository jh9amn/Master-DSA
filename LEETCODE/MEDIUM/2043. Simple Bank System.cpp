class Bank {
private:
    vector<long long> balance;
    int N;
public:
    Bank(vector<long long>& balance) {
        this->balance = balance;
        N = balance.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1-1 <= N and account2-1 <= N and balance[account1-1] >= money){
            balance[account1-1] -= money;
            balance[account2-1] += money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(N <= account-1 || money < 0){
            return false;
        }
        balance[account-1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account-1 <= N and balance[account-1] >= money){
            balance[account-1] -= money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
