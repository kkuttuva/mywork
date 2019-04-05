/*
 * [1,2,5] 11
 * [1] 0
 * [2] 3
 * [1] 1
 * [1,2,5] 2
 * [5,2,3] 6
 * [5,2,3] 12
 */

// Leetcode : 322. Coin Change

int coinChange(vector<int>& coins, int amount) {
    vector<int> count(amount + 1, -1);
    if(amount == 0) {
        return 0; // Missed this case while submitting
    }
    sort(coins.begin(), coins.end());
    count[0] = -1;
    for(int c = 0; c < coins.size(); c++) {
        if(coins[c] > amount) {
            break;
        }
        count[coins[c]] = 1;
    }
    for(int i = 1; i <= amount; i++) {
        int min = -1;
        if(count[i] != -1) {
            continue;
        }
        for(int c = 0; c < coins.size(); c++) {
            if(coins[c] > i) {
                break;
            }
            if(count[i-coins[c]] == -1) {
                continue;
            }
            int change = 1 + count[ i - coins[c] ];
            if (( min == -1) || (change < min)) {
                min = change;
            }
        }
        count[i] = min;
    }
    return count[amount];
 //   return coinChangeH(coins, amount, count);
}
