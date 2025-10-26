


typedef struct {
    long long* balance;
    int balanceSize;
} Bank;


Bank* bankCreate(long long* balance, int balanceSize) {
    Bank* b = malloc(sizeof(Bank));
    b->balance = malloc(balanceSize*sizeof(long long));
    memcpy(b->balance, balance, balanceSize*sizeof(long long));
    b->balanceSize = balanceSize;
    return b;
}

bool bankTransfer(Bank* obj, int account1, int account2, long long money) {
    account1--; account2--;
    if(account1 < 0 || account1 >= obj->balanceSize)return false;
    if(account2 < 0 || account2 >= obj->balanceSize)return false;

    if(obj->balance[account1] >= money){
        
        obj->balance[account1]-=money;
        obj->balance[account2]+=money;
        return true;
    }
    return false;
}

bool bankDeposit(Bank* obj, int account, long long money) {
        account--;
    if(account < 0 || account >= obj->balanceSize)return false;
    obj->balance[account]+=money;
    return true;
}

bool bankWithdraw(Bank* obj, int account, long long money) {
        account--;
    if(account < 0 || account >= obj->balanceSize)return false;
    if(obj->balance[account] >= money){
        obj->balance[account]-=money;
        return true;
    }
    return false;
}

void bankFree(Bank* obj) {
    free(obj->balance);
    free(obj);
    obj = NULL;
}

/**
 * Your Bank struct will be instantiated and called as such:
 * Bank* obj = bankCreate(balance, balanceSize);
 * bool param_1 = bankTransfer(obj, account1, account2, money);
 
 * bool param_2 = bankDeposit(obj, account, money);
 
 * bool param_3 = bankWithdraw(obj, account, money);
 
 * bankFree(obj);
*/