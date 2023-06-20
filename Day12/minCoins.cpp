/*
Find the minimum number of coins required to make a change.
The denominations are [1, 2, 5, 10, 20, 50, 100, 500, 1000]

T.C - O(Amount)
S.C - O(1)
*/

#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    int coins = 0;
    vector<int> den = {1000, 500, 100, 50, 20, 10, 5, 2, 1};

    int money = amount;
    int i = 0;
    while(money) {
        coins += (money / den[i]);
        money = money % den[i];
        i++;
    }

    return coins;
}
